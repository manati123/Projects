#pragma once
#include "Repo.h"
#include "Domain.h"
#include<assert.h>
#include<string>
#include<iostream>
#include<sstream>

//DomainTests
void DomainGetters_CreateAnItem_NameWasAdded();
void DomainGetters_CreateAnItem_AgeWasAdded();
void DomainGetters_CreateAnItem_MaterialWasAdded();
void DomainGetters_CreateAnItem_FormWasAdded();

void DomainSetters_ItemExists_NewNameWasSet();
void DomainSetters_ItemExists_NewMaterialWasSet();
void DomainSetters_ItemExists_NewFormWasSet();
void DomainSetters_ItemExists_NewAgeWasSet();

void toString_StreamExists_NameWasAdded();
void toString_StreamExists_MaterialWasAdded();
void toString_StreamExists_FormWasAdded();
void toString_StreamExists_AgeWasAdded();

//RepoTests
void addRepo_RepoIsEmpty_NameWasAdded();
void addRepo_RepoIsEmpty_MaterialWasAdded();
void addRepo_RepoIsEmpty_FormWasAdded();
void addRepo_RepoIsEmpty_AgeWasAdded();
void addRepo_ItemWithNameAlreadyExisted_ReturnsFalse();

void updateRepo_ItemExists_AgeUpdated();
void updateRepo_ItemExists_MaterialUpdated();
void updateRepo_ItemExists_FormUpdated();
void updateRepo_ItemDoesNotExist_ReturnsFalse();

void deleteRepo_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne();

void getRepo_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore();

//ServiceTests
void addService_RepoIsEmpty_NameWasAdded();
void addService_RepoIsEmpty_MaterialWasAdded();
void addService_RepoIsEmpty_FormWasAdded();
void addService_RepoIsEmpty_AgeWasAdded();
void addService_ItemWithNameAlreadyExisted_ReturnsFalse();

void updateService_ItemExists_AgeUpdated();
void updateService_ItemExists_MaterialUpdated();
void updateService_ItemExists_FormUpdated();
void updateService_ItemDoesNotExist_ReturnsFalse();

void deleteService_ItemExistedOnSecondPosition_SizeOfTheVectorDecrementedByOne();
void getRepoService_RepoExists_ReturnsTheRepoThatWasInstantiatedBefore();

//RepoIteratorTests
void save_itemExists_NameWasAdded();
void save_itemExists_MaterialWasAdded();
void save_itemExists_AgeWasAdded();
void save_itemExists_FormWasAdded();

void next_vectorHasAnItem_NameReturned();
void next_vectorHasAnItem_MaterialReturned();
void next_vectorHasAnItem_FormReturned();
void next_vectorHasAnItem_AgeReturned();
void next_vectorHasTwoItems_NameReturned();
void next_vectorHasTwoItems_FormReturned();
void next_vectorHasTwoItems_AgeReturned();
void next_vectorHasTwoItems_MaterialReturned();
void next_itemHasOnlyOneItem_SecondNextReturnsTheItem();

void getCurrentPosition_NextWasCalledOnce_ReturnsZero();

void getSizeOfMyVector_VectorHasOneItem_ReturnsOne();

void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_NameAdded();
void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_MaterialAdded();
void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_FormAdded();
void getAllByMaterialAndLesserValue_ThereIsAnItemThatIsOkWithThat_AgeAdded();
void getAllByMaterialAndLesserValue_NoItemComplies_ReturnTheWholeVector();

//TestIteratorService
void saveService_itemExists_NameWasAdded();
void saveService_itemExists_MaterialWasAdded();
void saveService_itemExists_AgeWasAdded();
void saveService_itemExists_FormWasAdded();

void nextService_vectorHasAnItem_NameReturned();
void nextService_vectorHasAnItem_MaterialReturned();
void nextService_vectorHasAnItem_FormReturned();
void nextService_vectorHasAnItem_AgeReturned();
void nextService_vectorHasTwoItems_NameReturned();
void nextService_vectorHasTwoItems_FormReturned();
void nextService_vectorHasTwoItems_AgeReturned();
void nextService_vectorHasTwoItems_MaterialReturned();
void nextService_itemHasOnlyOneItem_SecondNextReturnsTheItem();

void getCurrentPositionService_NextWasCalledOnce_ReturnsZero();

void getSizeOfMyVectorService_VectorHasOneItem_ReturnsOne();

void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_NameAdded();
void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_MaterialAdded();
void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_FormAdded();
void getAllByMaterialAndLesserValueService_ThereIsAnItemThatIsOkWithThat_AgeAdded();
void getAllByMaterialAndLesserValueService_NoItemComplies_ReturnTheWholeVector();

void getMyVectorService_VectorExists_ItIsTheSameAsTheOriginal();
void undo_addWasDoneBefore_itemIsUndone();

//FileRepoTests
void writeHTML_vectorWithTwoItems_FileIsWritten();
//RunAll
void runAll();