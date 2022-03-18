#include "string_t.h"


void free_string(String *string) {
    if (!string) {
        return;
    }
    if (!string->data) {
        return;
    }
    free(string->data);
    string->data = NULL;
    string->size = 0;
    string->capacity = 0;
}

int resize_string(String *string) {
    if (!string) {
        return -1;
    }

    size_t new_capacity = string->capacity >= MIN_SIZE ? string->capacity * 2 : MIN_SIZE;
    char *temp = calloc(new_capacity, sizeof(char));
    if (!temp) {
        return -1;
    }

    memcpy(temp, string->data, string->capacity);
    free(string->data);
    string->data = temp;
    string->capacity = new_capacity;
    return 0;
}

int add_char(String *string, const char c) {
    if (!string) {
        return -1;
    }

    if (string->size + 1 >= string->capacity) {
        if (resize_string(string)) {
            return -1;
        }
    }

    string->data[string->size] = c;
    ++string->size;
    return 0;
}

int read_string(String *string, const char delim, FILE *stream) {
    if (!string || !stream) {
        return -1;
    }

    char c = 0;
    while (fscanf(stream, "%c", &c) == 1) {
        if (c == delim) {
            break;
        }
        if (c != '\n' && c != '\t') {
            if (add_char(string, c)) {
                return -1;
            }
        }
    }

    return 0;
}
