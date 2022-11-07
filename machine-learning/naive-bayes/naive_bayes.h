#ifndef NAVIE_BAYES_H
#define NAVIE_BAYES_H

#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>


class naive_bayes_model {
    using value_type = std::vector<std::string>;
    using assoc_type = std::unordered_multimap<std::string, value_type>;
    using unique_type = std::map<std::string, value_type>;
public:
    naive_bayes_model() = default;
    void push_data(std::string_view key, const value_type& value);
    void train();
    auto predicate(std::string_view contents) -> std::string_view;
    void print_log();

private:
    auto get_features() -> value_type;
    auto get_unique_datasets() -> unique_type;

private:
    assoc_type dataSets_;
    std::map<std::string, double> priorProbability_;
    std::map<std::string, double> conditionalProbability_;
    std::map<std::string, double> posteriorProbability_;
};

#endif // NAVIE_BAYES