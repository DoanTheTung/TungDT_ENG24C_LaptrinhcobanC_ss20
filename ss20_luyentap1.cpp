#include <stdio.h>
#include <string.h>
struct Book {
    int id;
    char title[100];
    char author[100];
    double price;
    char category[50];
};
void displayBooks(struct Book books[], int n) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n", 
               books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
    }
}
void addBookAtPosition(struct Book books[], int *n, int position) {
    if (*n >= 50 || position < 0 || position > *n) {
        printf("\nKhong the them sach o vi tri nay.\n");
        return;
    }
    struct Book newBook;
    	printf("\nNhap thong tin sach moi:\n");
    	printf("Ma sach: ");
    	scanf("%d", &newBook.id);
    	getchar();
    	printf("Ten sach: ");
    	fgets(newBook.title, sizeof(newBook.title), stdin);
    	newBook.title[strcspn(newBook.title, "\n")] = '\0';
    	printf("Tac gia: ");
    	fgets(newBook.author, sizeof(newBook.author), stdin);
    	newBook.author[strcspn(newBook.author, "\n")] = '\0';
    	printf("Gia: ");
    	scanf("%lf", &newBook.price);
    	getchar();
    	printf("The loai: ");
    	fgets(newBook.category, sizeof(newBook.category), stdin);
    	newBook.category[strcspn(newBook.category, "\n")] = '\0';
    for (int i = *n; i > position; i--) {
        books[i] = books[i - 1];
    }
    books[position] = newBook;
    (*n)++;
}
void deleteBookById(struct Book books[], int *n, int id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (books[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("\nSach co ma %d da bi xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ma %d.\n", id);
    }
}
void updateBookById(struct Book books[], int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("\nNhap thong tin moi cho sach:\n");
            printf("Ten sach: ");
            getchar();
            fgets(books[i].title, sizeof(books[i].title), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';
            printf("Tac gia: ");
            fgets(books[i].author, sizeof(books[i].author), stdin);
            books[i].author[strcspn(books[i].author, "\n")] = '\0';
            printf("Gia: ");
            scanf("%lf", &books[i].price);
            getchar();
            printf("The loai: ");
            fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].category[strcspn(books[i].category, "\n")] = '\0';
            printf("\nThong tin sach da duoc cap nhat.\n");
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach voi ma %d.\n", id);
    }
}
void sortBooksByPrice(struct Book books[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && books[i].price > books[j].price) ||
                (!ascending && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("\nDanh sach sach da duoc sap xep theo gia.\n");
}
void searchBookByTitle(struct Book books[], int n, char *title) {
    int found = 0;
    printf("\nKet qua tim kiem:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(books[i].title, title)) {
            found = 1;
            printf("Ma sach: %d, Ten sach: %s, Tac gia: %s, Gia: %.2f, The loai: %s\n", 
                   books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
        }
    }
    if (!found) {
        printf("\nKhong tim thay sach co ten: %s\n", title);
    }
}
int main() {
    struct Book books[50];
    int n = 0;
    int choice;
    do{
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (1-Tang, 0-Giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1://Nhap so luong va thong tin sach
                printf("\nNhap so luong sach: ");
                scanf("%d", &n);
                getchar();
                for (int i = 0; i < n; i++) {
                    printf("\nNhap thong tin sach thu %d:\n", i + 1);
                    printf("Ma sach: ");
                    scanf("%d", &books[i].id);
                    getchar();
                    printf("Ten sach: ");
                    fgets(books[i].title, sizeof(books[i].title), stdin);
                    books[i].title[strcspn(books[i].title, "\n")] = '\0';
                    printf("Tac gia: ");
                    fgets(books[i].author, sizeof(books[i].author), stdin);
                    books[i].author[strcspn(books[i].author, "\n")] = '\0';
                    printf("Gia: ");
                    scanf("%lf", &books[i].price);
                    getchar();
                    printf("The loai: ");
                    fgets(books[i].category, sizeof(books[i].category), stdin);
                    books[i].category[strcspn(books[i].category, "\n")] = '\0';
                }
                break;
            case 2:// Hien thi thong tin sach
                displayBooks(books, n);
                break;
            case 3:// Them sach vao vi tri
                printf("\nNhap vi tri can them: ");
                int position;
                scanf("%d", &position);
                addBookAtPosition(books, &n, position);
                break;
            case 4:// Xoa sach theo ma sach
                printf("\nNhap ma sach can xoa: ");
                int deleteId;
                scanf("%d", &deleteId);
                deleteBookById(books, &n, deleteId);
                break;
            case 5://Cap nhat thong tin sach theo ma sach
                printf("\nNhap ma sach can cap nhat: ");
                int updateId;
                scanf("%d", &updateId);
                updateBookById(books, n, updateId);
                break;
            case 6://Sap xep sach theo gia (1-Tang, 0-Giam)
                printf("\nNhap lua chon (1-Tang, 0-Giam): ");
                int ascending;
                scanf("%d", &ascending);
                sortBooksByPrice(books, n, ascending);
                break;
            case 7://Tim kiem sach theo ten sach
                printf("\nNhap ten sach can tim: ");
                getchar();
                char searchTitle[100];
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = '\0';
                searchBookByTitle(books, n, searchTitle);
                break;
            case 8: //Thoat chuong trinh
                printf("\nThoat chuong trinh.\n");
                break;
            default:
                printf("\nLua chon khong hop le.\n");
                break;
        }
    } while (choice != 8);
    return 0;
}
