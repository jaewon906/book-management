#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 struct DataList 
 { 
 	char *bookName; 
 	char *writer; 
 	int publicationYear; 
 	char *publisher; 
 	char *genre; 
 	struct DataList *nextList; 
 }; 
 
 
 struct DataList* FileIn(struct DataList *dataStart) { 

 
 	struct DataList *loopLiked = dataStart; 
 
 
 	char *strInFileName; 
 	FILE *inFile; 

 
 	strInFileName = "C:/Users/Woo/Desktop/input.txt"; 
 
 
 	if ((inFile = fopen(strInFileName, "r")) == NULL) { 
 		printf("출력 파일 열기 실패\n"); 
 		exit(1); 
 	} 

 
 	int ibuffer; 
 	char buffer[4][100]; 
 
 
 	while (!feof(inFile)) { 
 
 
 		fscanf(inFile, "%s %s %d %s %s", buffer[0], buffer[1], &ibuffer, buffer[2], buffer[3]); 
 		char *out[4]; 
	for (int i = 0; i < 4; i++) { 
			out[i] = malloc(sizeof(char) * (strlen(buffer[i]))); 
			strcpy(out[i], buffer[i]); 
		} 
 
 
 		struct DataList *newData = malloc(sizeof(struct DataList) * 1); 
 		newData->bookName = out[0]; 
 		newData->writer = out[1];  		newData->publicationYear = ibuffer; 
 		newData->publisher = out[2];  		newData->genre = out[3]; 
 		newData->nextList = NULL;  
 
 		if (dataStart == NULL) { 
 			dataStart = newData; 
 			loopLiked = dataStart; 
 		} 
 		else {  			loopLiked->nextList = newData; 
 			loopLiked = loopLiked->nextList; 
 		} 
 
 
 		//printf("%s %s %d %s %s \n", buffer[0], buffer[1], &ibuffer, buffer[2], buffer[3]); 
 
 
 	} 
 	fclose(inFile); 
 	printf("File load OK\n"); 
 	return dataStart; 
} 
 
 
 void FileOut(struct DataList *printNode) { 
 	char *strOutFileName; 
 	FILE *outFile; 
 
 
 	strOutFileName = "C:/Users/Woo/Desktop/input.txt"; 

 
 	if ((outFile = fopen(strOutFileName, "w")) == NULL) { 
 		printf("출력 파일 열기 실패\n"); 
 		exit(1); 
 	} 
 
 
 	while (printNode != NULL) { 
 		if (printNode->nextList == NULL) { 
 			fprintf(outFile, "%s %s %d %s %s", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre); 
 		} 
 		else { 
 			fprintf(outFile, "%s %s %d %s %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre); 
 		} 
 		printNode = printNode->nextList; 
 	} 
 
 
 
 
 	fclose(outFile); 
 	printf("File Save OK\n"); 
 } 
 
 
 void PrintBook(struct DataList *dataStart); 
 
 
 char* In_String() {		//문자열 입력에 맞게 공간조정 
 	char buffer[100]; 
 	scanf("%s", buffer); 
 	char *out = malloc(sizeof(char) * (strlen(buffer))); 
 	strcpy(out, buffer); 
 	return out; 
 } 
 
 
 struct DataList* AddBook(struct DataList *dataStart) { 
 	struct DataList* loopLinkd = dataStart; 
 
 
 	printf("추가할 도서를 입력하세요. \n"); 
 	printf("(도서명, 저자, 출판연도, 출판사명, 장르 순으로 띄어 입력)\n"); 
 	struct DataList *newData = malloc(sizeof(struct DataList) * 1); 
 	newData->bookName = In_String(); 
 	newData->writer = In_String(); 
 	scanf("%d", &newData->publicationYear); 
 	newData->publisher = In_String(); 
 	newData->genre = In_String();; 
 	newData->nextList = NULL; 
 
 
 	if (dataStart == NULL) { 
 		dataStart = newData; 
 	} 
 	else { 
 		while (loopLinkd->nextList != NULL) { 
 			loopLinkd = loopLinkd->nextList; 
 		} 
 		loopLinkd->nextList = newData; 
 	} 
 
 
 	return dataStart; 
 } 
 struct DataList* SearchNode(struct DataList *testNode, char *sTest) { 
 	char sValue[10]; 
 	if (testNode == NULL) { 
 		return NULL; 
 	} 
 	else { 
 		while (testNode != NULL) { 
 			if (strstr(testNode->bookName, sTest) != NULL) { 
 				return testNode; 
 			} 
 			else if (strstr(testNode->writer, sTest) != NULL) { 
 				return testNode; 
 			} 
 			else if (strstr(_itoa(testNode->publicationYear, sValue, 10), sTest) != NULL) { 
 				return testNode; 
 			} 
 			else if (strstr(testNode->publisher, sTest) != NULL) { 
 				return testNode; 
 			} 
 			else if (strstr(testNode->genre, sTest) != NULL) { 
 				return testNode; 
 			} 
			else { 
 				testNode = testNode->nextList; 
 			} 
 		} 
 		return NULL; 
 	} 
 } 
 
 
 void SearchBook(struct DataList *loopLinkd) { 
 
 
 	printf("도서검색\n"); 
 	printf("(도서명, 저자, 출판연도, 출판사명, 장르 검색가능)\n"); 
 	printf("검색할 단어를 입력하세요: "); 
 	char *sTest = In_String(); 
 	printf("\n"); 
 	printf("-----------------------------------\n"); 
 	struct DataList *printNode; 
 	int c = 0; 
 	while (loopLinkd != NULL) { 
 
 
 		printNode = SearchNode(loopLinkd, sTest); 
 
 
 		if (printNode == NULL) { 
 
 
 			break; 
 		} 
 		else { 
 			printf("%s, %s, %d, %s, %s\n", printNode->bookName, printNode->writer, printNode->publicationYear, printNode->publisher, printNode->genre); 
 			loopLinkd = printNode->nextList; 
 		} 
 		c++; 
 	} 
 	printf("-----------------------------------\n"); 
 	printf("검색결과: 총 (%d)건 입니다.\n", c); 
 } 
 
 
 void EditBook(struct DataList *dataStart) { 
 	if (dataStart == NULL) { 
 		return; 
 	} 
 	PrintBook(dataStart); 
 
 
	struct DataList* testNode = dataStart; 
 	while (1) { 
 		printf("\n수정할 도서명을 정확히 입력하세요:"); 
 		char *delBookName = In_String(); 
 
 
 		while (testNode != NULL) { 
 			if (strcmp(testNode->bookName, delBookName) == 0) { 
 				break; 
 			} 
 			else { 
 				testNode = testNode->nextList; 
 			} 
 		} 
		if (testNode == NULL) { 
 			testNode = dataStart; 
 			printf("검색된 도서명이 없습니다.\n"); 
 		} 
 		else { 
 			break; 
		} 
 
 
	} 
 
 
 	printf("수정할 목록을 선택하세요(1.도서명 2.저자 3.출판연도 4.출판사명 5.장르) : "); 
 	int sel; 
 	while (1) { 
 		scanf("%d", &sel); 
 		switch (sel) 
 		{ 
 		case 1: 
 			printf("변경할 도서명 입력 : "); 
 			testNode->bookName = In_String(); 
 			break; 
 		case 2: 
 			printf("변경할 저자 입력 : "); 
 			testNode->writer = In_String(); 
 			break; 
 		case 3: 
 			printf("변경할 출판연도 입력 : "); 
 			int year; 
 			scanf("%d", &year); 
 			testNode->publicationYear = year; 
 			break; 
 		case 4: 
 			printf("변경할 출판사명 입력 : "); 
 			testNode->publisher = In_String(); 
 			break; 
 		case 5: 
 			printf("변경할 출판사명 입력 : "); 
 			testNode->genre = In_String(); 
			break; 
		default: 
 			printf("잘못된 입력입니다. 다시입력하세요:"); 
 			continue; 
 			break; 
 		} 
 		break; 
 	} 
 	printf("\n수정완료 :"); 
 	printf("%s %s %d %s %s\n", testNode->bookName, testNode->writer, testNode->publicationYear, testNode->publisher, testNode->genre); 
 
 
 } 
 
 
 struct DataList* DeleteBook(struct DataList *dataStart) { 
 	PrintBook(dataStart); 
 
 
 	struct DataList* testNode = dataStart; 
 
 
 	while (1) { 
		printf("\n삭제랑 도서명을 정확히 입력하세요:"); 
 		char *delBookName = In_String(); 
 		while (testNode != NULL) { 
 			if (strcmp(testNode->bookName, delBookName) == 0) { 
 				break; 
 			} 
 			else { 
			testNode = testNode->nextList; 
 			} 
		} 
 		if (testNode == NULL) { 
 			testNode = dataStart; 
 			printf("검색된 도서명이 없습니다.\n"); 
 		} 
 		else { 
 			break; 
 		} 
 	} 
 	struct DataList* loopNode = dataStart; 
 	if (testNode == dataStart) { 
 		dataStart = dataStart->nextList; 
 		free(testNode); 
 	} 
 	else { 
 		while (loopNode != NULL) { 
			if (loopNode->nextList == testNode) { 
 				break; 
 			} 
 			else { 
 				loopNode = loopNode->nextList; 
			} 
 		} 
 		loopNode->nextList = testNode->nextList; 
 		free(testNode); 
	} 
 	printf("정상 삭제 되었습니다.\n"); 
 	return dataStart; 
 } 
 
 
 void PrintBook(struct DataList *dataStart) { 
 	struct DataList *loopLinkd = dataStart; 
 	printf("\n도서명 저자 출판연도 출판사명 장르\n"); 
	printf("-----------------------------------\n"); 
 	while (loopLinkd != NULL) { 
		printf("%s %s %d %s %s\n", loopLinkd->bookName, loopLinkd->writer, loopLinkd->publicationYear, loopLinkd->publisher, loopLinkd->genre); 
 		loopLinkd = loopLinkd->nextList; 
 	} 
 	printf("-----------------------------------\n"); 
 } 
 void menu(struct DataList *dataStart) { 
 
 
 	int sel; 
 	while (1) { 
 		printf("=======================\n"); 
 		printf("1.도서 추가 \n"); 
 		printf("2.도서 검색 \n"); 
 		printf("3.도서 정보 수정 \n"); 
 		printf("4.도서 삭제 \n"); 
 		printf("5.현재 총 도서 목록 출력 \n"); 
 		printf("6.저장 \n"); 
 		printf("7.프로그램 나가기(자동저장) \n"); 
 		printf("입력: "); 
 		scanf("%d", &sel); 
		printf("\n"); 
		switch (sel) 
 		{ 
 		case 1: 
 			printf("1.도서 추가 \n"); 
 			dataStart = AddBook(dataStart); 
 			break; 
 		case 2: 
 			printf("2.도서 검색 \n"); 
 			SearchBook(dataStart); 
 			break; 
 		case 3: 
			printf("3.도서 정보 수정 \n"); 
 			EditBook(dataStart); 
 			break; 
 		case 4:  			printf("4.도서 삭제 \n"); 
 			dataStart = DeleteBook(dataStart); 
 			break; 
 		case 5: 
 			printf("5.현재 총 도서 목록 출력 \n"); 
 			PrintBook(dataStart); 
 			break; 
 		case 6: 
 			printf("6.저장 \n"); 
 			FileOut(dataStart); 
 			break; 
 		case 7: 
 			printf("7.프로그램 나가기(자동저장) \n"); 
 			FileOut(dataStart); 
 			return; 
 			break; 
 		default: 
 			printf("다시입력하세요.\n"); 
			break; 
 		} 
 		printf("\n"); 
 	} 
 } 
 
 
 int main() { 
 
 
 	struct DataList *dataStart = NULL; 
 	dataStart = FileIn(dataStart); 
	menu(dataStart); 
 
 
 	return 0; 
 } 
