#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for sleep

#define STR_SIZE 100

char* createMessage(int i) {
    char* buffer = (char*)malloc(STR_SIZE);
    if (!buffer) {
        printf("Memory allocation failed at iteration %d\n", i);
        exit(1);
    }
    snprintf(buffer, STR_SIZE, "Message number %d", i);
    return buffer;  // ❗ הערך הזה לעולם לא ישוחרר!
}

int main() {
    int counter = 0;

    while (1) {
        char* msg = createMessage(counter);
        printf("%s\n", msg);

        // ❗ באג: לא נעשה free(msg)
        // התוכנית יוצרת עוד ועוד הקצאות מבלי לשחרר אותן

        counter++;
        sleep(1);  // השהייה כדי לראות את ההדפסות
    }

    return 0;
}
