#include "naive_bayes.h"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string_view>
#include <utility>

void naive_bayes_model::push_data(
    std::string_view key, const value_type& value) {
    dataSets_.emplace(std::make_pair(key, value));
}

void naive_bayes_model::train() {
    // Prior Probability
    int dataSize = dataSets_.size();
    std::ranges::for_each(dataSets_, [&](const auto& item) {
        if (!priorProbability_.contains(item.first)) {
            int size = dataSets_.count(item.first);
            priorProbability_[item.first] = size / (double)dataSize;
        }
    });

    // Conditional Probability
    auto features = get_features();
    auto uniqueDatasets = get_unique_datasets();
    for (const auto& [key, values] : uniqueDatasets) {
        std::ranges::for_each(features, [&](const auto& feature) {
            // Laplace Smoothing
            auto count = std::ranges::count(values, feature) + 1;
            conditionalProbability_[feature + "|" + key] = (double)count / (values.size() + features.size());
        });
    }
}

auto naive_bayes_model::get_features() -> value_type {
    std::vector<std::string> features;
    int size = 0;
    
    // Preallocates the size of features
    std::ranges::for_each(dataSets_, [&size](const auto& item) {
        size += item.second.size();
    });
    features.reserve(size);

    // Push all data into features
    std::ranges::for_each(dataSets_, [&features](const auto& item) {
        std::ranges::copy(item.second, std::back_inserter(features));
    });

    // Removes duplicate elements in features
    std::ranges::sort(features);
    const auto ret = std::ranges::unique(features);
    features.erase(ret.begin(), ret.end());

    return features;
}

auto naive_bayes_model::get_unique_datasets() -> unique_type {
    std::map<std::string, value_type> uniqueDatasets;
    
    std::ranges::for_each(dataSets_, [&uniqueDatasets](const auto& item) {
        if (!uniqueDatasets.contains(item.first)) {
            uniqueDatasets[item.first] = {};
        }
        std::ranges::copy(item.second, std::back_inserter(uniqueDatasets[item.first]));
    });

    return uniqueDatasets;
}

auto naive_bayes_model::predicate(std::string_view contents) -> std::string_view {
    // parse the features
    auto words = contents
                | std::views::split(' ')
                | std::views::transform([](auto&& str) {
                    return std::string_view(&*str.begin(), std::ranges::distance(str)); 
                });

    for (const auto& [key, value] : priorProbability_) {
        double probability = priorProbability_[key];
        for (auto&& word : words) {
            probability *= conditionalProbability_[std::string(word) + "|" + key];
        }
        std::string index { key + "|" };
        index += contents;
        if (!posteriorProbability_.contains(index))
            posteriorProbability_[index] = probability;
    }

    // Choose the maximum probability.
    auto highest = std::ranges::max(posteriorProbability_ | std::views::values);
    const auto& res = std::ranges::find_if(posteriorProbability_, [&highest](const auto& item) {
        return item.second == highest;
    });

    return std::string_view(&res->first[0], res->first.find("|"));
}

void naive_bayes_model::print_log() {
    std::cout << "Training datasets:\n";
    std::ranges::for_each(dataSets_, [](const auto& item) {
        std::cout << item.first << "\t: [ ";
        std::ranges::for_each(item.second, [](const auto& e) {
            std::cout << e << " ";
        });
        std::cout << "]\n";
    });

    std::cout << "----------------------------------\nPrior Probability: \n";
    std::ranges::for_each(priorProbability_, [](const auto& item) {
        std::cout << item.first << ": " << item.second << "\n";
    });

    std::cout << "----------------------------------\nFeatures:\n";
    for (const auto& e : get_features()) {
        std::cout << e << " ";
    }

    std::cout << "----------------------------------\nunique datasets:\n";
    for (const auto& [key, value] : get_unique_datasets()) {
        std::cout << key << ": ";
        for (const auto& e : value)
            std::cout << e << " ";
        std::cout << "\n";
    }

    std::cout << "----------------------------------\nConditional Probability:\n";
    std::ranges::for_each(conditionalProbability_, [](const auto& item) {
        std::cout << item.first << "\t: " << item.second << "\n";
    });

    std::cout << "----------------------------------\nPosterior Probability: \n";
    std::ranges::for_each(posteriorProbability_, [](const auto& item) {
        std::cout << item.first << ": " << item.second << "\n";
    });
}