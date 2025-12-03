#include<iostream>
#include<memory>
#include<vector>
#include "Test.h"

// --- Function Prototypes ---
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();

void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num);

void display(const std::vector<std::shared_ptr<Test>>& vec);

int main()
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	size_t num;
	std::cin >> num;
    fill(*vec_ptr, num);
	display(*vec_ptr);


}

// --- Implementations---

std::unique_ptr<std::vector<std::shared_ptr<Test>>>make()
{
	auto ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
	return ptr;
}

void fill(std::vector<std::shared_ptr<Test>>& vec, size_t num)
{
	int temp_data{0};
	
	for (size_t i{ 0 }; i < num; i++)
	{
		std::cout << "Enter data point: [" << i << "] : ";
		std::cin >> temp_data;
		vec.push_back(std::make_shared<Test>(temp_data));
	}

}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{
	std::cout << "\nDisplaying vector data" << std::endl;
	std::cout << "=======================" << std::endl;
	for (const auto& ptr : vec)
	{
		std::cout << ptr->get_data() << std::endl;
	}
}