#include <iostream>
#include <vector>
#include <string>

void print_vector(const std::vector<std::string>& vs_name, const std::vector<double> vi_age);
std::vector<std::string> copy_vector(const std::vector<std::string>& vs_name);
std::vector<double> sort_age(const std::vector<std::string>& vs_name, std::vector<std::string> copy_vs_name, const std::vector<double> vd_age);

int main()
{
    std::vector<std::string> vs_name;
    std::vector<double> vd_age;

    std::cout << "How many persons: ";
    int number;
    std::cin >> number;

    std::cout << "Their names: ";

    for (int i = 0; i < number; ++i)
    {
        std::string name;
        std::cin >> name;
        vs_name.push_back(name);
    }

    std::cout << "Their ages: ";

    for (int i = 0; i < number; ++i)
    {
        double age;
        std::cin >> age;
        vd_age.push_back(age);
    }

    print_vector(vs_name, vd_age);

    std::vector<std::string> copy_vs_name = copy_vector(vs_name);
    sort(vs_name.begin(), vs_name.end());

    std::vector<double> sorted_age = sort_age(vs_name, copy_vs_name, vd_age);

    print_vector(vs_name, sorted_age);

    std::cin.get();
}

void print_vector(const std::vector<std::string>& vs_name, const std::vector<double> vd_age)
{
    for (int i = 0; i < vs_name.size(); ++i)
    {
        std::cout << "(" << vs_name[i] << ", " << vd_age[i] << ")" << std::endl;
    }
}

std::vector<std::string> copy_vector(const std::vector<std::string>& vs_name)
{
    std::vector<std::string> result;

    for (std::string name : vs_name)
    {
        result.push_back(name);
    }

    return result;
}

std::vector<double> sort_age(const std::vector<std::string>& vs_name, std::vector<std::string> copy_vs_name, const std::vector<double> vd_age)
{
    std::vector<double> result;

    for (std::string name : vs_name)
    {
        int index = &*std::find(copy_vs_name.begin(), copy_vs_name.end(), name) - &copy_vs_name[0];
        result.push_back(vd_age[index]);
    }

    return result;
}