//#include "Tests.h"
//#include "Service.h"
//#include<vector>
//#include "FileRepo.h"
//#include <fstream>
////DomainTests
//void DomainGetters_CreateAnItem_NameWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	assert(item.getName() == "123");
//}
//
//void DomainGetters_CreateAnItem_AgeWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	assert(item.getAge() == 123);
//}
//void DomainGetters_CreateAnItem_MaterialWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	assert(item.getMaterial() == "123");
//}
//void DomainGetters_CreateAnItem_FormWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	assert(item.getForm() == "123");
//}
//
//void DomainSetters_ItemExists_NewNameWasSet()
//{
//	Domain item;
//	item.setName("123");
//	assert(item.getName() == "123");
//}
//void DomainSetters_ItemExists_NewMaterialWasSet()
//{
//	Domain item;
//	item.setMaterial("123");
//	assert(item.getMaterial() == "123");
//}
//void DomainSetters_ItemExists_NewFormWasSet()
//{
//	Domain item;
//	item.setForm("123");
//	assert(item.getForm() == "123");
//}
//void DomainSetters_ItemExists_NewAgeWasSet()
//{
//	Domain item;
//	item.setAge(123);
//	assert(item.getAge() == 123);
//}
//
//void toString_StreamExists_NameWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	std::stringstream stringStream = item.toString();
//	std::string name, material, form;
//	//int age;
//	stringStream >> name;
//	assert(name == "123");
//}
//void toString_StreamExists_MaterialWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	std::stringstream stringStream = item.toString();
//	std::string name, material, form;
//	//int age;
//	stringStream >> name >> material;
//	assert(material == "123");
//}
//void toString_StreamExists_FormWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	std::stringstream stringStream = item.toString();
//	std::string name, material, form;
//	//int age;
//	stringStream >> name >> material >> form;
//	assert(form == "123");
//}
//void toString_StreamExists_AgeWasAdded()
//{
//	Domain item{ "123","123",123,"123" };
//	std::stringstream stringStream = item.toString();
//	std::string name, material, form;
//	int age;
//	stringStream >> name >> material >> form >> age;
//	assert(age == 123);
//}
//
////RepoTests
//void addRepo_RepoIsEmpty_NameWasAdded()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" };
//	repo.addRepo(item);
//	assert(item.getName() == "123");
//}
//void addRepo_RepoIsEmpty_MaterialWasAdded()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" };
//	repo.addRepo(item);
//	assert(item.getMaterial() == "123");
//}
//void addRepo_RepoIsEmpty_FormWasAdded()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" };
//	repo.addRepo(item);
//	assert(item.getForm() == "123");
//}
//void addRepo_RepoIsEmpty_AgeWasAdded()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" };
//	repo.addRepo(item);
//	assert(repo[0].getAge() == 123);
//}
//
//void addRepo_ItemWithNameAlreadyExisted_ReturnsFalse() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" };
//	repo.addRepo(item);
//	assert(repo.addRepo(item) == false);
//}
//
//void updateRepo_ItemExists_AgeUpdated()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	//repo.addRepo(updateItem);
//	repo.updateRepo(updateItem);
//	assert(repo[0].getAge() == 333);
//}
//void updateRepo_ItemExists_MaterialUpdated()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.updateRepo(updateItem);
//	assert(repo[0].getMaterial() == "333");
//}
//void updateRepo_ItemExists_FormUpdated()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.updateRepo(updateItem);
//	assert(repo[0].getForm() == "333");
//}
//void updateRepo_ItemDoesNotExist_ReturnsFalse() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	assert(repo.updateRepo(item) == false);
//}
//
//void deleteRepo_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	//std::cout << updateItem.getName();
//	repo.deleteRepo(updateItem.getName());
//	//std::vector<Domain>::iterator iterator = repo.getRepo().begin();
//	assert(repo.getSize() == 1);
//}
//
//void getRepo_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore()
//{
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	std::vector<Domain> vector = repo.getRepo();
//	assert(repo.getRepo()[0].getAge() == vector[0].getAge());
//}
//
////ServiceTests
//void addService_RepoIsEmpty_NameWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(repo[0].getName() == "123");
//}
//void addService_RepoIsEmpty_MaterialWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(repo[0].getMaterial() == "123");
//}
//void addService_RepoIsEmpty_FormWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(repo[0].getForm() == "123");
//}
//void addService_RepoIsEmpty_AgeWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(repo[0].getAge() == 123);
//}
//void addService_ItemWithNameAlreadyExisted_ReturnsFalse() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(service.addService("123", "123", "123", 123) == false);
//}
//
//void updateService_ItemExists_AgeUpdated() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	service.updateService("123", "333", "333", 333);
//	assert(repo[0].getAge() == 333);
//}
//void updateService_ItemExists_MaterialUpdated() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	service.updateService("123", "333", "333", 333);
//	assert(repo[0].getMaterial() == "333");
//}
//void updateService_ItemExists_FormUpdated() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	service.updateService("123", "333", "333", 333);
//	assert(repo[0].getForm() == "333");
//}
//void updateService_ItemDoesNotExist_ReturnsFalse() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	assert(service.updateService("133323", "333", "333", 333) == false);
//}
//
//void deleteService_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	//Domain item{ "123","123","123",123 }, updateItem{ "333","333","333",333 };
//	service.addService("123", "123", "123", 123);
//	service.addService("333", "333", "333", 333);
//	service.deleteService("333");
//	assert(service.getSizeOfRepo() == 1);
//}
//void getRepoService_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	service.addService("123", "123", "123", 123);
//	std::vector<Domain> vector = service.getRepoService();
//	assert(repo.getRepo()[0].getAge() == vector[0].getAge());
//}
////RepoIteratorTests
//void save_itemExists_NameWasAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.save(item.getName());
//	assert(repo.getMyVector()[0].getName() == item.getName());
//}
//void save_itemExists_MaterialWasAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.save(item.getName());
//	assert(repo.getMyVector()[0].getMaterial() == item.getMaterial());
//
//}
//void save_itemExists_AgeWasAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.save(item.getName());
//	assert(repo.getMyVector()[0].getAge() == item.getAge());
//
//}
//void save_itemExists_FormWasAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	repo.save(item.getName());
//	assert(repo.getMyVector()[0].getForm() == item.getForm());
//
//}
//
//void next_vectorHasAnItem_NameReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	Domain nextItem = repo.next();
//	assert(nextItem.getName() == item.getName());
//}
//void next_vectorHasAnItem_MaterialReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	Domain nextItem = repo.next();
//	assert(nextItem.getMaterial() == item.getMaterial());
//}
//void next_vectorHasAnItem_FormReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	Domain nextItem = repo.next();
//	assert(nextItem.getForm() == item.getForm());
//}
//void next_vectorHasAnItem_AgeReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	Domain nextItem = repo.next();
//	assert(nextItem.getAge() == item.getAge());
//}
//void next_itemHasOnlyOneItem_SecondNextReturnsTheItem() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "123","333",333,"333" };
//	repo.addRepo(item);
//	Domain nextItem = repo.next();
//	nextItem = repo.next();
//	assert(nextItem.getName() == item.getName());
//}
//void next_vectorHasTwoItems_NameReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	Domain nextItem = repo.next();
//	nextItem = repo.next();
//	assert(nextItem.getName() == updateItem.getName());
//}
//void next_vectorHasTwoItems_FormReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	Domain nextItem = repo.next();
//	nextItem = repo.next();
//	assert(nextItem.getForm() == updateItem.getForm());
//}
//void next_vectorHasTwoItems_AgeReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	Domain nextItem = repo.next();
//	nextItem = repo.next();
//	assert(nextItem.getAge() == updateItem.getAge());
//}
//void next_vectorHasTwoItems_MaterialReturned() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	Domain nextItem = repo.next();
//	nextItem = repo.next();
//	assert(nextItem.getMaterial() == updateItem.getMaterial());
//}
//
//
//void getCurrentPosition_NextWasCalledOnce_ReturnsZero() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.next();
//	assert(repo.getCurrentPosition() == 0);
//}
//
//void getSizeOfMyVector_VectorHasOneItem_ReturnsOne() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.save(item.getName());
//	assert(repo.getSizeOfMyVector() == 1);
//}
//
//void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_NameAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = repo.getAllByMaterialAndLesserValue(item.getMaterial(), 124);
//	assert(vector[0].getName() == item.getName());
//}
//void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_MaterialAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = repo.getAllByMaterialAndLesserValue(item.getMaterial(), 124);
//	assert(vector[0].getMaterial() == item.getMaterial());
//}
//void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_FormAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = repo.getAllByMaterialAndLesserValue(item.getMaterial(), 124);
//	assert(vector[0].getForm() == item.getForm());
//}
//void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_AgeAdded() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = repo.getAllByMaterialAndLesserValue(item.getMaterial(), 124);
//	assert(vector[0].getAge() == item.getAge());
//}
//void getAllByMaterialAndLesserValue_NoItemComplies_ReturnTheWholeVector() {
//	Repo repo;
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = repo.getAllByMaterialAndLesserValue(item.getMaterial(), 90);
//	int index = 0;
//	for (auto& element : vector) {
//		assert(element.getName() == repo.getRepo()[index].getName());
//		index++;
//	}
//}
////TestIteratorService
//void saveService_itemExists_NameWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.saveService(item.getName());
//	assert(repo.getMyVector()[0].getName() == item.getName());
//}
//void saveService_itemExists_MaterialWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.saveService(item.getName());
//	assert(repo.getMyVector()[0].getMaterial() == item.getMaterial());
//}
//void saveService_itemExists_AgeWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.saveService(item.getName());
//	assert(repo.getMyVector()[0].getAge() == item.getAge());
//}
//void saveService_itemExists_FormWasAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.saveService(item.getName());
//	assert(repo.getMyVector()[0].getForm() == item.getForm());
//}
//
//void nextService_vectorHasAnItem_NameReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	assert(service.nextService().getName() == item.getName());
//}
//void nextService_vectorHasAnItem_MaterialReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	assert(service.nextService().getMaterial() == item.getMaterial());
//}
//void nextService_vectorHasAnItem_FormReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	assert(service.nextService().getForm() == item.getForm());
//}
//void nextService_vectorHasAnItem_AgeReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	assert(service.nextService().getAge() == item.getAge());
//}
//void nextService_vectorHasTwoItems_NameReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	service.nextService();
//	assert(service.nextService().getName() == updateItem.getName());
//}
//void nextService_vectorHasTwoItems_FormReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	service.nextService();
//	assert(service.nextService().getForm() == updateItem.getForm());
//}
//void nextService_vectorHasTwoItems_AgeReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	service.nextService();
//	assert(service.nextService().getAge() == updateItem.getAge());
//}
//void nextService_vectorHasTwoItems_MaterialReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	service.nextService();
//	assert(service.nextService().getMaterial() == updateItem.getMaterial());
//}
//void nextService_itemHasOnlyOneItem_SecondNextReturnsTheItem() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.nextService();
//	assert(service.nextService().getName() == item.getName());
//}
//
//void getCurrentPositionService_NextWasCalledOnce_ReturnsZero() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.nextService();
//	assert(service.getCurrentPositionService() == 0);
//}
//
//void getSizeOfMyVectorService_VectorHasOneItem_ReturnsOne() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	service.saveService("123");
//	assert(service.getSizeOfMyVectorService() == 1);
//}
//
//void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_NameAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = service.getAllByMaterialAndLesserValueService(item.getMaterial(), 124);
//	assert(vector[0].getName() == item.getName());
//}
//void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_MaterialAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = service.getAllByMaterialAndLesserValueService(item.getMaterial(), 124);
//	assert(vector[0].getMaterial() == item.getMaterial());
//}
//void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_FormAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = service.getAllByMaterialAndLesserValueService(item.getMaterial(), 124);
//	assert(vector[0].getForm() == item.getForm());
//}
//void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_AgeAdded() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = service.getAllByMaterialAndLesserValueService(item.getMaterial(), 124);
//	assert(vector[0].getAge() == item.getAge());
//}
//void getAllByMaterialAndLesserValueService_NoItemComplies_ReturnTheWholeVector() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	std::vector<Domain> vector = service.getAllByMaterialAndLesserValueService(item.getMaterial(), 124);
//	assert(vector[0].getAge() == item.getAge());
//}
//void getMyVectorService_VectorExists_ItIsTheSameAsTheOriginal() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo,fileRepo };
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	repo.addRepo(item);
//	repo.addRepo(updateItem);
//	repo.save("123");
//	repo.save("333");
//	std::vector<Domain> vector = service.getMyVectorService();
//	int index = 0;
//	for (auto& element : vector) {
//		assert(element.getName() == repo.getRepo()[index].getName());
//		index++;
//	}
//}
//
////FileRepoTests
//void writeToFile_fileIsCreated_readingFromItWillGiveBackTheString() {
//	std::ofstream file("C:\\Users\\Silviu\\Desktop\\fisierutulet.txt");
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	file << item;
//	file << updateItem;
//	file.close();
//	std::ifstream fileReader("C:\\Users\\Silviu\\Desktop\\fisierutulet.txt");
//	Domain readOne{};
//	fileReader >> readOne;
//	assert(readOne.getName() == item.getName());
//
//
//}
//
//void readFromFile_fileExisted_readingWillGiveAString() {
//	Domain item{ "123","123",123,"123" }, updateItem{ "333","333",333,"333" };
//	std::ifstream fileReader("C:\\Users\\Silviu\\Desktop\\fisierutulet.txt");
//	Domain readOne{};
//	fileReader >> readOne;
//	assert(readOne.getName() == item.getName());
//	fileReader.close();
//
//}
//void readFromFile_fileExists_itHasAnInvalidEntry() {
//	std::ifstream fileReader("C:\\Users\\Silviu\\Desktop\\fisierutulet.txt");
//	Domain item{ "123","123",123,"123" };
//	fileReader >> item;
//	assert(item.getName() == "123");
//}
//void write_RepoHasAnElement_WillBeWrittenAndReadingWillGiveBackTheCorrectItem() {
//	Domain item{ "123","123",123,"123" };
//
//	FileRepo fileRepo;
//	Repo repo;
//	Service service{ repo, fileRepo };
//	repo.addRepo(item);
//	service.writeToFile("C:\\Users\\Silviu\\Desktop\\testuleanu.txt");
//	//std::vector<Domain> vector = service.readFromFile("C:\\Users\\Silviu\\Desktop\\testuleanu.txt");
//	Repo anotherRepo;
//	FileRepo anotherFileRepo;
//	Service anotherService{ anotherRepo, anotherFileRepo };
//	anotherService.readFromFile("C:\\Users\\Silviu\\Desktop\\testuleanu.txt");
//	assert(anotherRepo.getRepo()[0].getName() == "123");
//
//}
//void read_TheFolderHasAn_ItemIsReturned() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	service.readFromFile("C:\\Users\\Silviu\\Desktop\\testuleanu.txt");
//	assert(repo.getRepo()[0].getName() == "123");
//}
//
//void undo_addWasDoneBefore_itemIsUndone() {
//	Repo repo;
//	FileRepo fileRepo;
//	Service service{ repo, fileRepo };
//	service.addService("a", "b", "c", 234);
//	service.undo();
//
//	//assert(service.getSizeOfRepo() == 1230);
//}
//
////RunAll
//void runAll()
//{
//	//DomainTests
//	DomainGetters_CreateAnItem_NameWasAdded();
//	DomainGetters_CreateAnItem_AgeWasAdded();
//	DomainGetters_CreateAnItem_MaterialWasAdded();
//	DomainGetters_CreateAnItem_FormWasAdded();
//	DomainSetters_ItemExists_NewNameWasSet();
//	DomainSetters_ItemExists_NewMaterialWasSet();
//	DomainSetters_ItemExists_NewFormWasSet();
//	DomainSetters_ItemExists_NewAgeWasSet();
//	toString_StreamExists_NameWasAdded();
//	toString_StreamExists_MaterialWasAdded();
//	toString_StreamExists_FormWasAdded();
//	toString_StreamExists_AgeWasAdded();
//	std::cout << "Domain tests finished!" << std::endl;
//	//RepoTests
//	addRepo_ItemWithNameAlreadyExisted_ReturnsFalse();
//	addRepo_RepoIsEmpty_NameWasAdded();
//	addRepo_RepoIsEmpty_MaterialWasAdded();
//	addRepo_RepoIsEmpty_FormWasAdded();
//	addRepo_RepoIsEmpty_AgeWasAdded();
//	updateRepo_ItemExists_AgeUpdated();
//	updateRepo_ItemExists_MaterialUpdated();
//	updateRepo_ItemExists_FormUpdated();
//	updateRepo_ItemDoesNotExist_ReturnsFalse();
//	deleteRepo_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne();
//	getRepo_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore();
//	std::cout << "Repo tests finished!" << std::endl;
//	//ServiceTests
//	addService_RepoIsEmpty_NameWasAdded();
//	addService_RepoIsEmpty_MaterialWasAdded();
//	addService_RepoIsEmpty_FormWasAdded();
//	addService_RepoIsEmpty_AgeWasAdded();
//	addService_ItemWithNameAlreadyExisted_ReturnsFalse();
//
//	updateService_ItemExists_AgeUpdated();
//	updateService_ItemExists_MaterialUpdated();
//	updateService_ItemExists_FormUpdated();
//	updateService_ItemDoesNotExist_ReturnsFalse();
//
//	deleteService_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne();
//	getRepoService_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore();
//	std::cout << "Service tests finished!" << std::endl;
//
//	//RepoIteratorTests
//	save_itemExists_NameWasAdded();
//	save_itemExists_MaterialWasAdded();
//	save_itemExists_AgeWasAdded();
//	save_itemExists_FormWasAdded();
//
//	next_vectorHasAnItem_NameReturned();
//	next_vectorHasAnItem_MaterialReturned();
//	next_vectorHasAnItem_FormReturned();
//	next_vectorHasAnItem_AgeReturned();
//	next_vectorHasTwoItems_NameReturned();
//	next_vectorHasTwoItems_FormReturned();
//	next_vectorHasTwoItems_AgeReturned();
//	next_vectorHasTwoItems_MaterialReturned();
//	next_itemHasOnlyOneItem_SecondNextReturnsTheItem();
//
//	getCurrentPosition_NextWasCalledOnce_ReturnsZero();
//
//	getSizeOfMyVector_VectorHasOneItem_ReturnsOne();
//
//	getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_NameAdded();
//	getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_MaterialAdded();
//	getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_FormAdded();
//	getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_AgeAdded();
//	getAllByMaterialAndLesserValue_NoItemComplies_ReturnTheWholeVector();
//	std::cout << "Repo iterator tests passed!" << std::endl;
//	//TestIteratorService
//	saveService_itemExists_NameWasAdded();
//	saveService_itemExists_MaterialWasAdded();
//	saveService_itemExists_AgeWasAdded();
//	saveService_itemExists_FormWasAdded();
//
//	nextService_vectorHasAnItem_NameReturned();
//	nextService_vectorHasAnItem_MaterialReturned();
//	nextService_vectorHasAnItem_FormReturned();
//	nextService_vectorHasAnItem_AgeReturned();
//	nextService_vectorHasTwoItems_NameReturned();
//	nextService_vectorHasTwoItems_FormReturned();
//	nextService_vectorHasTwoItems_AgeReturned();
//	nextService_vectorHasTwoItems_MaterialReturned();
//	nextService_itemHasOnlyOneItem_SecondNextReturnsTheItem();
//
//	getCurrentPositionService_NextWasCalledOnce_ReturnsZero();
//
//	getSizeOfMyVectorService_VectorHasOneItem_ReturnsOne();
//
//	getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_NameAdded();
//	getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_MaterialAdded();
//	getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_FormAdded();
//	getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_AgeAdded();
//	getAllByMaterialAndLesserValueService_NoItemComplies_ReturnTheWholeVector();
//
//	getMyVectorService_VectorExists_ItIsTheSameAsTheOriginal();
//	std::cout << "Service iterator tests finished!" << std::endl;
//
//	//FileRepoTests
//	writeToFile_fileIsCreated_readingFromItWillGiveBackTheString();
//	readFromFile_fileExisted_readingWillGiveAString();
//	readFromFile_fileExists_itHasAnInvalidEntry();
//	//write_RepoHasAnElement_WillBeWrittenAndReadingWillGiveBackTheCorrectItem();
//	//read_TheFolderHasAn_ItemIsReturned();
//	std::cout << "File repository tests finished!" << std::endl;
//}