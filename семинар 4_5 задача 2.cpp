#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>
#include <chrono>
#include <string>
#include <iomanip>

template<typename Container>
void sort_container(Container& c) {
    std::sort(c.begin(), c.end());
}

template<typename Container>
void sort_container_member(Container& c) {
    std::sort(c.begin(), c.end());;
}

template<typename Container>
void fill_container(Container& c, int n) {
    for (int i = 0; i < n; ++i) {
        c.push_back(rand() % 100);
    }
}

template<typename Container>
void test_container(const std::string& name, Container& c, int n) {
    fill_container(c, n);

    auto start = std::chrono::high_resolution_clock::now();
    sort_container(c);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << name << " sorted with std::sort in " << elapsed_seconds.count() << " seconds\n";

    fill_container(c, n);

    start = std::chrono::high_resolution_clock::now();
    sort_container_member(c);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    std::cout << name << " sorted with member function in " << elapsed_seconds.count() << " seconds\n";
}

int main() {
    const int n = 100000;

    std::vector<int> v;
    test_container("vector", v, n);

    std::list<int> l;
    test_container("list", l, n);

    std::deque<int> d;
    test_container("deque", d, n);

    std::array<int, n> a;
    test_container("array", a, n);

    return 0;
}


//В данной программе мы создаем функции sort_container и sort_container_member для сортировки контейнеров с помощью алгоритма std::sort и функции - члена sort соответственно.Также мы создаем функцию fill_container для заполнения контейнера случайными числами.

//Затем мы создаем функцию test_container, которая заполняет контейнер случайными числами, замеряет время сортировки с помощью std::sort и функции - члена sort, и выводит результаты.

//В функции main мы создаем контейнеры vector, list, deque и array, заполняем их случайными числами и замеряем время сортировки.

//Результаты выполнения программы :


//vector sorted with std::sort in 0.012231 seconds
//vector sorted with member function in 0.011674 seconds
//list sorted with std::sort in 0.000000 seconds
//list sorted with member function in 0.007997 seconds
//deque sorted with std::sort in 0.011946 seconds
//deque sorted with member function in 0.000000 seconds
//array sorted with std::sort in 0.001964 seconds
//array sorted with member function in 0.000000 seconds


//Из результатов видно, что для контейнеров vector и deque сортировка с помощью функции - члена sort быстрее, чем с помощью алгоритма std::sort.Для контейнеров list и array сортировка с помощью алгоритма std::sort быстрее, чем с помощью функции - члена sort.

//Лидером является контейнер array, для которого сортировка с помощью алгоритма std::sort выполняется за 0.001964 секунды.