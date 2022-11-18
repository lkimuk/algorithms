#ifndef NAVIE_BAYES_H
#define NAVIE_BAYES_H

#include <initializer_list>
#include <map>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>


class naive_bayes_model {
    using value_type  = std::vector<std::string>;
    using assoc_type  = std::unordered_multimap<std::string, value_type>;
    using unique_type = std::map<std::string, value_type>;
    using pair_type   = std::pair<std::string_view, value_type>;

public:
    naive_bayes_model() = default;
    naive_bayes_model(std::initializer_list<pair_type> elems);

    // 添加数据
    void push_data(std::string_view key, value_type value);
    
    // 训练模型
    void train();
    
    // 预测分类
    auto predict(std::string_view contents) -> std::string_view;
    
    // 打印日志
    void print_log();

private:
    
    // 获取特征
    auto get_features() -> value_type;
    
    // 获取去重的数据集
    auto get_unique_datasets() -> unique_type;

private:
    assoc_type dataSets_;
    std::map<std::string, double> priorProbability_;        // 先验概率
    std::map<std::string, double> conditionalProbability_;  // 条件概率
    std::map<std::string, double> posteriorProbability_;    // 后验概率
};

#endif // NAVIE_BAYES