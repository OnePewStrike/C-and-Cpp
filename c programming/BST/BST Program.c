/* 
 * Binary Search Tree -- Linked List Implementation
 * source code written for data handling of a enterprise's sales and accounts
 * name: Rual Godwin C. Duliente
 * start: 17/10/2021 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define FLUSH while(getchar()!='\n')

typedef struct {
	int itemId;
	char itemName[30];
	int quantity;
	float sellPrice;
}ITEM;

typedef struct {
	int userId;
	char userName[40];
}CUSTOMER;

typedef struct {
	char salesNumber[30];
	char customerId[4];
	char itemId[4];
	int quantitySold;
}SALES;

typedef struct node * nd;
struct node {
	ITEM item;
	CUSTOMER customer;
	SALES sales;
	nd left;
	nd right;
}NODE;

bool searchItem(nd *, int);
bool searchUser(nd *, int);
bool searchDelete(nd *, nd *, int);
bool deleteLeaf(nd *, nd *, nd *);
bool deleteOneChild(nd *, nd *, nd *);
bool deleteTwoChildren(nd *, nd *);

ITEM createItem(nd);
CUSTOMER createUser(nd);
SALES createSales();
int showMenuOptions();
void addNewItem(nd *, ITEM);
void addNewCustomer(nd *, CUSTOMER);
void addNewSales(nd *, SALES);
void deleteItem(nd *);
void displayItems(nd);
void displaySales(nd);
bool itemUpdate(nd *, int, int); 
void verifySales(nd *, nd *, nd *, SALES); 

int main (void) {
	int choice, searchKey;
	bool itemExist, userExist, deleted;
	nd itemRoot = NULL, userRoot = NULL, salesRoot = NULL;
	ITEM newItem;
	CUSTOMER newUser;
	SALES newSales;

	do {
		choice = showMenuOptions();
		switch (choice) {
			case 1:
				newItem = createItem(itemRoot);
				addNewItem(&itemRoot, newItem);	
				break;
			case 2:
				newUser = createUser(userRoot);
				addNewCustomer(&userRoot, newUser);
				break;
			case 3:
				deleteItem(&itemRoot);
				break;
			case 4:
				newSales = createSales();
				verifySales(&salesRoot, &itemRoot, &userRoot, newSales);
				addNewSales(&salesRoot, newSales);
				break;
			case 5:
				displayItems(itemRoot);
				break;
			case 6:
				printf("\nExiting...");
				break;
			case 8:
				displaySales(salesRoot);
				break;
			default:
				continue;
		}	
	} while (choice != 6);
	printf("\nEnd of Program");
	return 0;
}

int showMenuOptions() {
	int choice;
	printf("\n\nDuliente Enterprise"
			"\n1. Add New Item"
			"\n2. Add New Customer" 
			"\n3. Delete an Item" 
			"\n4. Sales" 
			"\n5. Display All Items"
			"\n6. Exit"
			"\nEnter choice: ");
	scanf("%d", &choice);
	FLUSH;
	return choice;
}

void verifySales(nd *salesRoot, nd *itemRoot, nd *userRoot, SALES newSales) {
	nd salesPtr = *salesRoot, itemPtr = *itemRoot, userPtr = *userRoot;
	bool itemExist, userExist, itemIsNegative, failedConditions = false;	
	int searchKey;
	
	printf("\nVerifying transaction details..."
			"\nVerifying customer's id...");
	searchKey = atoi(newSales.customerId); // convert char customerId to integer
	userExist = searchUser(&userPtr, searchKey);
	if (userExist) {
		printf("\nCustomer id verified...");
	} else {
		printf("\nCustomer id does not exist..."
				"\nTherefore not satisfying conditions... returning to menu...");
		return;
	}
	
	printf("\nVerifying item id...");
	searchKey = atoi(newSales.itemId); // convert char itemId to integer
	itemExist = searchItem(&itemPtr, searchKey);
	if(itemExist) {
		printf("\nItem id verified...");
	} else {
		printf("\nItem id does not exist..."
				"\nTherefore not satisfying conditions... returning to menu...");
		return;
	}
		
	printf("\nVerifying quantity on hand...");	
	if (newSales.quantitySold <= 0) {
		printf("\nThe quantity on hand is already zero..."
				"\nTherefore not satisfying conditions... returning to menu...");
		return;
	} else {
		printf("\nThe quantity on hand is not zero...");
	}
				
	printf("\nVerying quantity bought...");
	searchKey = atoi(newSales.itemId); // convert string item id to integer
	itemIsNegative = itemUpdate(&itemPtr, searchKey, newSales.quantitySold);
	if (itemIsNegative) {
		printf("\nThe quantity bought is negative..."
				"\nTherefore not satisfying conditions... returning to menu...");
		return;
	} else {
		printf("\nThe quantity bought is not negative...");
	}
			
	if(failedConditions) {
		printf("\nSome conditions were not satisfied... returning to menu...");
	} else {
		printf("\nItem quantity is decreased...");
		printf("\nSales transaction number is %s...", newSales.salesNumber);
	}	
	return;
}

void addNewSales(nd *root, SALES newSales) {
	nd ptr, ptr1;
	nd temp = malloc(sizeof(NODE));
	temp->sales = newSales;
	temp->left = NULL;
	temp->right = NULL;
	int salesNumberOne, salesNumberTwo;
	salesNumberOne = atoi(temp->sales.salesNumber);
	
	if (*root == NULL) {
		*root = temp;
	} else {
		ptr = *root;
		while(ptr != NULL) {
			ptr1 = ptr;
			salesNumberTwo = atoi(ptr->sales.salesNumber);
			if(salesNumberOne < salesNumberTwo) { 
				ptr = ptr->left;
			} else {
				ptr = ptr->right;
			} 
		} 
		if (salesNumberOne < salesNumberTwo) {
			ptr1->left = temp;
		} else {
			ptr1->right = temp;
		}
	} 
	return;
}

SALES createSales() {	
	SALES newSales;
	char quantitySold[4];
	printf("\nAdding new sales transaction..."
			"\nPlease enter the customer's id: ");
	gets(newSales.customerId);
	printf("Please enter the item's id: ");
	gets(newSales.itemId);
	printf("Please enter the amount that the customer bought: ");
	scanf("%d", &newSales.quantitySold);
	FLUSH;

	// sales transaction number
	strcpy(newSales.salesNumber, newSales.customerId);
	strcat(newSales.salesNumber, newSales.itemId);
	strcat(newSales.salesNumber, newSales.customerId);
	strcat(newSales.salesNumber, newSales.itemId);
	sprintf(quantitySold, "%d", newSales.quantitySold); // convert integer quantitySold to char
	strcat(newSales.salesNumber, quantitySold);
	
	return newSales;
}

void displayItems(nd root) { 
	if (root == NULL) {
		printf("\nThere are no items recorded yet...");
		return;
	} else {
		if (root->left != NULL) {
			displayItems(root->left);
		}
		printf("\n--------------------------");
		printf("\nItem id: %d", root->item.itemId);
		printf("\nItem name: %s", root->item.itemName);
		printf("\nItem quantity: %d", root->item.quantity);
		printf("\nItem selling price: %.2f", root->item.sellPrice);
		printf("\n--------------------------");
		if (root->right != NULL) {
			displayItems(root->right);
		}		
	}

}

void displaySales(nd root) { // inorder display
	if (root == NULL) {
		return;
	} else {
		if (root != NULL) {
			displaySales(root->left);
			printf("\n--------------------------");
			printf("\nCustomer id: %s", root->sales.customerId);
			printf("\nItem id: %s", root->sales.itemId);
			printf("\nQuantity sold: %d", root->sales.quantitySold);
			printf("\nTransaction number: %s", root->sales.salesNumber);
			printf("\n--------------------------");
			displaySales(root->right);
		}
	}
}

void deleteItem(nd *root) {
	int searchKey;
	bool doesExist, deleted;
	nd ptr = *root, ptr1 = NULL;
	
	printf("\nDeleting a item..."
			"\nPlease input the item id to be deleted: ");
	scanf("%d", &searchKey);
	FLUSH;
	
	doesExist = searchDelete(&ptr, &ptr1, searchKey);
	if (doesExist) {
		printf("\nAre you sure you want to delete the item? (space to cancel)");
		if (getch() != ' ') {
			if ((ptr->left == NULL) && (ptr->right == NULL)) {
				deleted = deleteLeaf(root, &ptr, &ptr1);
			} else if ((ptr->left != NULL) && (ptr->right != NULL)) {
				deleted = deleteTwoChildren(&ptr, &ptr1);
			} else {
				deleted = deleteOneChild(root, &ptr, &ptr1);
			}
			if (deleted) {
				printf("\n\nSuccessfully deleted item id %d...", searchKey);
			} else {
				printf("\n\nError: unable to delete item ...");
			}		
			getch();				
		} else {
			printf("\nItem deletion is cancelled...");
			getch();
		}
	} else {
		printf("\n\nError: The item was not found...");
		getch();
	}
}

ITEM createItem(nd root) {
	bool itemExist;
	ITEM newItem;
	char name[40];
	int nameSize, quantity, id;
	float price;
	printf("\nAdding new item..."
			"\nPlease enter item number: ");
	scanf("%d", &id);
	FLUSH;
	printf("Please enter item name: ");
	gets(name);
	nameSize = strlen(name);
	printf("Please enter item quantity: ");
	scanf("%d", &quantity);
	FLUSH;
	printf("Please enter item price: ");
	scanf("%f", &price);
	FLUSH;

	itemExist = searchItem(&root, id);
	if (itemExist) {
		printf("\nThere is a item id %d already recorded...", id);
		return createItem(root); 
	} else if (id < 0 || nameSize == 0 || quantity < 0 || id < 0) {
		printf("\nPlease fill the information required...");
		return createItem(root);
	}else {
		newItem.itemId = id;
		strcat(newItem.itemName, name);
		newItem.quantity = quantity;
		newItem.sellPrice = price;
		printf("\nSuccessfully added a new item...");
	}
	return newItem;
}

void addNewItem(nd *root, ITEM newItem) {
	nd ptr, ptr1;
	nd temp = malloc(sizeof(NODE));
	temp->item = newItem;
	temp->left = NULL;
	temp->right = NULL;
	
	if (*root == NULL) {
		*root = temp;
	} else {
		ptr = *root;
		while(ptr != NULL) {
			ptr1 = ptr;
			if(temp->item.itemId < ptr->item.itemId) { 
				ptr = ptr->left;
			} else {
				ptr = ptr->right;
			} 
		} 
		if (temp->item.itemId < ptr1->item.itemId) {
			ptr1->left = temp;
		} else {
			ptr1->right = temp;
		}
	} 
}

CUSTOMER createUser(nd root) {
	CUSTOMER newUser;
	bool userExist;
	int nameSize, id;
	char name[40];
	printf("\nAdding new customer..."
			"\nPlease enter a id number: ");
	scanf("%d", &id);
	FLUSH;
	printf("Please enter name: ");
	gets(name);
	nameSize = strlen(name);

	userExist = searchUser(&root, id);
	if (userExist) {
		printf("\nThere is a customer id %d already recorded...", id);
		return createUser(root);
	} else if (id < 0 || nameSize == 0) {
		printf("\nPlease fill the information required...");
		return createUser(root);
	}else {
		newUser.userId = id;
		strcat(newUser.userName, name);
		printf("\nSuccessfully added a new customer...");
	}

	return newUser;
}

void addNewCustomer(nd *root, CUSTOMER newUser) {
	nd ptr, ptr1;
	nd temp = malloc(sizeof(NODE));
	temp->customer = newUser;
	temp->left = NULL;
	temp->right = NULL;
	
	if (*root == NULL) {
		*root = temp;
	} else {
		ptr = *root;
		while(ptr != NULL) {
			ptr1 = ptr;
			if(temp->customer.userId < ptr->customer.userId) { 
				ptr = ptr->left;
			} else {
				ptr = ptr->right;
			} 
		} 
		if (temp->item.itemId < ptr1->item.itemId) {
			ptr1->left = temp;
		} else {
			ptr1->right = temp;
		}
	} 
	return;
}

bool itemUpdate(nd *ptr, int searchKey, int quantitySold) {
	bool itemExist = false, quantityIsNegative;
	int itemQuantity;

	while (*ptr != NULL) {
		if(searchKey == (*ptr)->item.itemId){
			itemExist = true;
			break; 
		}else if(searchKey < (*ptr)->item.itemId){
			*ptr = (*ptr)->left;
		} else {
			*ptr = (*ptr)->right;
		}
	}
	
	itemQuantity = (*ptr)->item.quantity;
	if (itemExist) {
		itemQuantity -= quantitySold;
		if (itemQuantity < 0) {
			quantityIsNegative = true;
		} else {
			(*ptr)->item.quantity -= quantitySold;
			quantityIsNegative = false;
		}
	} else {
		printf("\nThe item does not exist...");
	}
	return quantityIsNegative;
}

bool searchItem(nd *ptr, int searchKey) {
	bool doesExist = false;

	while (*ptr != NULL) {
		if(searchKey == (*ptr)->item.itemId){
			doesExist = true;
			break; 
		}else if(searchKey < (*ptr)->item.itemId){
			*ptr = (*ptr)->left;
		} else {
			*ptr = (*ptr)->right;
		}
	}
	return doesExist;
}

bool searchUser(nd *ptr, int searchKey) {
	bool doesExist = false;

	while (*ptr != NULL) {
		if(searchKey == (*ptr)->customer.userId){
			doesExist = true;
			break; 
		}else if(searchKey < (*ptr)->customer.userId){
			*ptr = (*ptr)->left;
		} else {
			*ptr = (*ptr)->right;
		}
	}
	return doesExist;
}

bool searchDelete(nd *ptr, nd *ptr1, int searchKey) {
	bool doesExist = false;
	
	while((*ptr)!=NULL){
		if (searchKey == (*ptr)->item.itemId){
			doesExist = true;
			break;
		} else {
			(*ptr1) = (*ptr);
			if(searchKey < (*ptr)->item.itemId) {
				(*ptr) = (*ptr)->left;
			} else {
 				(*ptr) = (*ptr)->right;
 			}
		}
	}
	return doesExist;
}

bool deleteLeaf(nd *root, nd *ptr, nd *ptr1) {
	if(*ptr == *root) {
		*root = NULL;
	} else {
		if((*ptr)->item.itemId < (*ptr1)->item.itemId) {
			(*ptr1)->left = NULL;
		} else {
			(*ptr1)->right = NULL;
		}
	}
	free(*ptr);
	return true;
}

bool deleteOneChild(nd *root, nd *ptr, nd *ptr1) {
	if (*root == *ptr) {
		if ((*ptr)->right == NULL) {
			*root = (*root)->left;
		} else {
			*root = (*root)->right;
		}
	} else {
		if((*ptr)->item.itemId <= (*ptr1)->item.itemId) {
			if((*ptr)->right == NULL) {
				(*ptr1)->left = (*ptr)->left;
			} else {
				(*ptr1)->left = (*ptr)->right;
			} 
		} else  {
			if((*ptr)->right == NULL) {
				(*ptr1)->right = (*ptr)->left;
			} else {
				(*ptr1)->right = (*ptr)->right;
			}
		}
	}
	free(*ptr);
	return true;
}

bool deleteTwoChildren(nd *ptr, nd *ptr1) { 
	nd ptr2 = NULL;
	
	*ptr1 = (*ptr)->right;
	while ((*ptr1)->left != NULL) {
		ptr2 = *ptr1;
		(*ptr1) = (*ptr1)->left;
	}
	(*ptr)->item = (*ptr1)->item;
	if(ptr2 == NULL){
		if((*ptr1)->right != NULL) {
			(*ptr)->right = (*ptr1)->right;
		} else {
 			(*ptr)->right = NULL;
 		}
	} else {
		if((*ptr1)->right == NULL) {
			ptr2->left = NULL;
		} else {
			ptr2->left = (*ptr1)->right;
		}
	}
	free(*ptr1);
	return true;
}

