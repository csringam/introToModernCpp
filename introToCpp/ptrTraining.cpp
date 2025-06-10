#include <iostream>
#include <string>
#include <memory>

class Project1 {
	std::string pName;
public:
	void setName(const std::string& name) {
		pName = name;
	}
	void showProjDetails() {
		std::cout << "Project Name: " << pName << std::endl;
	}
};

class Employee1 {
	std::shared_ptr<Project1> pProject{};
public:
	void setProject(std::shared_ptr<Project1>& project) {
		pProject = project;
	}
	const std::shared_ptr<Project1>& getProject() const {
		return pProject;
	}
};

void showInfo(const std::shared_ptr<Employee1>& emp) {
	std::cout << "Employee project details: ";
	emp->getProject()->showProjDetails();
}

void runDemosPtr() {
	std::shared_ptr<Project1> project{ new Project1{} };
	project->setName("Pointer Training");

	std::shared_ptr<Employee1> em1{ new Employee1{} };
	em1->setProject(project);

	std::shared_ptr<Employee1> em2{ new Employee1{} };
	em2->setProject(project);

	project->showProjDetails();
	showInfo(em1);
	showInfo(em2);

}