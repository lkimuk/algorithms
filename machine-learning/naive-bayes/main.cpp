#include "naive_bayes.h"
#include <iostream>

int main() {
    naive_bayes_model model;
    // model.push_data("normal message", {"my", "dog", "has", "flea", "problems", "help", "please"});
    // model.push_data("abusive message", {"maybe", "not", "take", "him", "to", "dog", "park", "stupid"});
    // model.push_data("normal message", {"my", "dalmation", "is", "so", "cute", "I", "love", "him"});
    // model.push_data("abusive message", {"stop", "posting", "stupid", "worthless", "garbage"});
    // model.push_data("normal message",  {"my", "licks", "ate", "my", "steak", "how", "to", "stop", "him"});
    // model.push_data("abusive message", {"quit", "buying", "worthless", "dog", "food", "stupid"});
    // model.push_data("abusive message", {"stupid", "worthless", "garbage", "stupid"});
    // model.push_data("Normal message", {"Dear", "Friend"});
    // model.push_data("Normal message", {"Dear", "Friend", "Money"});
    // model.push_data("Normal message", {"Dear", "Lunch", });
    // model.push_data("Normal message", {"Dear"});
    // model.push_data("Normal message", {"Dear", "Lunch"});
    // model.push_data("Normal message", {"Friend", "Dear"});
    // model.push_data("Normal message", {"Dear", "Lunch", "Friend"});
    // model.push_data("Normal message", {"Dear", "Friend"});
    // model.push_data("Spam", {"Dear", "Friend"});
    // model.push_data("Spam", {"Dear", "Money"});
    // model.push_data("Spam", {"Money", "Money"});
    // model.push_data("Spam", {"Money"});
    model.push_data("ºÃ¹Ï", {"ÎÚºÚ", "ÉÔòé", "×ÇÏì", "ÇåÎú", "ÉÔ°¼", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"ÎÚºÚ", "ÉÔòé", "×ÇÏì", "ÉÔºı", "ÉÔ°¼", "ÈíÕ³"});
    model.push_data("ºÃ¹Ï", {"ÇàÂÌ", "ÉÔòé", "×ÇÏì", "ÇåÎú", "ÉÔ°¼", "ÈíÕ³"});
    model.push_data("ºÃ¹Ï", {"Ç³°×", "òéËõ", "×ÇÏì", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"Ç³°×", "òéËõ", "×ÇÏì", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"ÇàÂÌ", "òéËõ", "³ÁÃÆ", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"ÎÚºÚ", "òéËõ", "×ÇÏì", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"ÎÚºÚ", "òéËõ", "³ÁÃÆ", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("ºÃ¹Ï", {"ÇàÂÌ", "òéËõ", "×ÇÏì", "ÇåÎú", "°¼Ïİ", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"ÇàÂÌ", "òéËõ", "³ÁÃÆ", "ÉÔºı", "ÉÔ°¼", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"Ç³°×", "òéËõ", "×ÇÏì", "Ä£ºı", "Æ½Ì¹", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"ÎÚºÚ", "ÉÔòé", "×ÇÏì", "ÇåÎú", "ÉÔ°¼", "ÈíÕ³"});
    model.push_data("»µ¹Ï", {"Ç³°×", "ÉÔòé", "³ÁÃÆ", "ÉÔºı", "°¼Ïİ", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"ÇàÂÌ", "ÉÔòé", "×ÇÏì", "ÉÔºı", "°¼Ïİ", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"Ç³°×", "òéËõ", "×ÇÏì", "Ä£ºı", "Æ½Ì¹", "ÈíÕ³"});
    model.push_data("»µ¹Ï", {"Ç³°×", "Ó²Í¦", "Çå´à", "Ä£ºı", "Æ½Ì¹", "Ó²»¬"});
    model.push_data("»µ¹Ï", {"ÇàÂÌ", "Ó²Í¦", "Çå´à", "ÇåÎú", "Æ½Ì¹", "ÈíÕ³"});
    model.push_data("»µ¹Ï", {"ÎÚºÚ", "ÉÔòé", "³ÁÃÆ", "ÉÔºı", "ÉÔ°¼", "Ó²»¬"});
    
    model.train();
    auto classification = model.predicate("ÇàÂÌ ÇåÎú ³ÁÃÆ ×ÇÏì");
    model.print_log();

    std::cout << "The classification is " << classification << "\n";
}