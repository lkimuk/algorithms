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
    model.push_data("�ù�", {"�ں�", "����", "����", "����", "�԰�", "Ӳ��"});
    model.push_data("�ù�", {"�ں�", "����", "����", "�Ժ�", "�԰�", "��ճ"});
    model.push_data("�ù�", {"����", "����", "����", "����", "�԰�", "��ճ"});
    model.push_data("�ù�", {"ǳ��", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("�ù�", {"ǳ��", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("�ù�", {"����", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("�ù�", {"�ں�", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("�ù�", {"�ں�", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("�ù�", {"����", "����", "����", "����", "����", "Ӳ��"});
    model.push_data("����", {"����", "����", "����", "�Ժ�", "�԰�", "Ӳ��"});
    model.push_data("����", {"ǳ��", "����", "����", "ģ��", "ƽ̹", "Ӳ��"});
    model.push_data("����", {"�ں�", "����", "����", "����", "�԰�", "��ճ"});
    model.push_data("����", {"ǳ��", "����", "����", "�Ժ�", "����", "Ӳ��"});
    model.push_data("����", {"����", "����", "����", "�Ժ�", "����", "Ӳ��"});
    model.push_data("����", {"ǳ��", "����", "����", "ģ��", "ƽ̹", "��ճ"});
    model.push_data("����", {"ǳ��", "Ӳͦ", "���", "ģ��", "ƽ̹", "Ӳ��"});
    model.push_data("����", {"����", "Ӳͦ", "���", "����", "ƽ̹", "��ճ"});
    model.push_data("����", {"�ں�", "����", "����", "�Ժ�", "�԰�", "Ӳ��"});
    
    model.train();
    auto classification = model.predicate("���� ���� ���� ����");
    model.print_log();

    std::cout << "The classification is " << classification << "\n";
}