#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_value(char *data, char *key, char *value) {
    char *pos = strstr(data, key);
    if (!pos) {
        value[0] = '\0';
        return;
    }
    pos += strlen(key);
    sscanf(pos, "%[^&]", value);
}

void to_upper(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = toupper((unsigned char)s[i]);
}

int main() {
    char *data = getenv("QUERY_STRING");

    char q[10][50];
    int score = 0;

    
    printf("Content-Type: text/html\n\n");
    printf("<!DOCTYPE html>");
    printf("<html>");
    printf("<head>");
    printf("<title>Quiz Result</title>");
    printf("<link rel='stylesheet' href='/quiz/style.css'>");
    printf("</head>");
    printf("<body>");

    printf("<div class='container'>");
    printf("<h2>Quiz Result</h2>");

    if (!data) {
        printf("<p>No data received.</p>");
        printf("</div></body></html>");
        return 0;
    }

    get_value(data, "q1=", q[0]);
    get_value(data, "q2=", q[1]);
    get_value(data, "q3=", q[2]);
    get_value(data, "q4=", q[3]);
    get_value(data, "q5=", q[4]);
    get_value(data, "q6=", q[5]);
    get_value(data, "q7=", q[6]);
    get_value(data, "q8=", q[7]);
    get_value(data, "q9=", q[8]);
    get_value(data, "q10=", q[9]);

    for (int i = 0; i < 10; i++)
        to_upper(q[i]);

    if (strcmp(q[0], "CPU") == 0) score++;
    if (strcmp(q[1], "INPUT DEVICE") == 0) score++;
    if (strcmp(q[2], "OUTPUT DEVICE") == 0) score++;
    if (strcmp(q[3], "PRIMARY MEMORY") == 0) score++;
    if (strcmp(q[4], "HARDWARE") == 0) score++;
    if (strcmp(q[5], "BIT") == 0) score++;
    if (strcmp(q[6], "SECONDARY MEMORY") == 0) score++;
    if (strcmp(q[7], "BROWSER") == 0) score++;
    if (strcmp(q[8], "HOMEPAGE") == 0) score++;
    if (strcmp(q[9], "SOFTWARE") == 0) score++;

    for (int i = 0; i < 10; i++)
        printf("<p>Q%d Answer: <strong>%s</strong></p>", i + 1, q[i]);

    printf("<h3 class='score'>Score: %d / 10</h3>", score);
    printf("<a class='btn' href='/quiz/quiz.html'>Try Again</a>");

    printf("</div>");
    printf("</body></html>");

    return 0;
}