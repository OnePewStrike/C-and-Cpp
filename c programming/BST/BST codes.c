oid addNewCustomer(nd *root, CUSTOMER newUser) {
	nd ptr, ptr1;
	nd temp = malloc(sizeof(NODE));
	temp->customer = newUser;
	temp->left = NULL;
	temp->right = NULL;
	int tempId = atoi(temp->customer.customerId), idPtr, idPtr1;
	// convert char customerId[] to integer for comparison
	
	if (*root == NULL) {
		*root = temp;
	} else {
		ptr = *root;
		while(ptr != NULL) {
			ptr1 = ptr;
			idPtr = atoi(ptr->customer.customerId);
			if(tempId < idPtr) { 
				ptr = ptr->left;
			} else {
				ptr = ptr->right;
			} 
		} 
		idPtr1 = atoi(ptr1->customer.customerId);
		if (tempId < idPtr1) {
			ptr1->left = temp;
		} else {
			ptr1->right = temp;
		}
	} 
	return;
}

bool searchUser(nd *ptr, char searchKey[]) {
	bool doesExist = false;
	while (*ptr != NULL) {
		if(searchKey == ptr){
			doesExist = true;
			break; 
		}else if(searchKey < ptr){
			*ptr = (*ptr)->left;
		} else {
			*ptr = (*ptr)->right;
		}
	}
	return doesExist;
}

bool searchDelete(nd *ptr, nd *ptr1, char searchKey[]) {
	bool doesExist = false;
	while (*ptr != NULL) {
		if (searchKey == ptr) {
			doesExist = true;
			break;
		} else {
			*ptr1 = *ptr;
			if (searchKey < ptr) {
				*ptr = (*ptr)->left;
			} else {
				*ptr = (*ptr)->right;
			}
		}
	}
	return doesExist;
}
bool deleteLeaf(nd *root, nd *ptr, nd *ptr1) {
	int idPtr, idPtr1;

	if(*ptr == *root) {
		*root = NULL;
	} else {
		if(*ptr < ptr1) {
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
		if(ptr <= ptr1) {
			if((*ptr)->right == NULL) {
				(*ptr1)->left = (*ptr)->left;
			} else {
				(*ptr1)->left = (*ptr)->right;
			} 
		} else  {
			if((*ptr)->right == NULL) {
				(*ptr1)->left = (*ptr)->left;
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