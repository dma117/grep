#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int check_line2(char *line, int len, char *pattern, int max_num) { //for case -m NUM
    size_t pattern_size = strlen(pattern);
    int checked = 0;
    int counter = 0;

    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size || counter == max_num) {
            printf("%s", line);
            counter++;
            break;
        }
        if (line[i] == pattern[checked]) {
            ++checked;
        } else
            checked = 0;
    }
    return 0;
}

int simple_v(char *line, int len, char *pattern) {
    size_t pattern_size = strlen(pattern);
    int checked = 0;
    int found = 0;
    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size) {
            found = 1;
            break;
        }
        if (line[i] == pattern[checked]) {
            ++checked;
        }
    }
    if (found == 0) {
        printf("%s", line);
    }
    return 0;
}

int options_v(char *line, int len, char *pattern, int *counter, int if_num) {
    size_t pattern_size = strlen(pattern);
    int checked = 0;
    int found = 0;
    int local_counter = 0;
    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size) {
            found = 1;
            break;
        }
        if (line[i] == pattern[checked]) {
            ++checked;
        }
    }
    if (found == 0) {
        local_counter += 1;
        *counter += local_counter;
        if (if_num != 0 && (*counter <= if_num)) {
            printf("%s", line);
        }
    }
    return 0;
}

void check_line_counter(char *line, int len, char *pattern, int *counter, int if_num) {
//    printf("in check_line_counter\n");
    size_t pattern_size = strlen(pattern);
    int checked = 0;
    int local_counter = 0;

    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size) {
            ++local_counter;
            if (if_num != 0 && ((*counter + local_counter) <= if_num)) {
                printf("%s", line);
                break;
            } else
                break;
        }
        if (line[i] == pattern[checked]) {
            ++checked;
        } else
            checked = 0;
    }
    *counter += local_counter;
}

int check_line(char *line, int len, char *pattern) {
    size_t pattern_size = strlen(pattern);
    int checked = 0;
    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size) {
            printf("%s", line);
            break;
        }
        if (line[i] == pattern[checked]) {
            ++checked;
        } else
            checked = 0;
    }
    return 0;
}

int check_get_line(char *line, int len, char *pattern, char *file) {
    size_t pattern_size = strlen(pattern);
    int checked = 0;


    for (int i = 0; i < len; ++i) {
        if (checked >= pattern_size) {
            printf("%s:%s", file, line);
            break;
        }
        if (line[i] == pattern[checked])
            ++checked;
        else
            checked = 0;
    }
    return 0;
}

int read_files(char *pattern, char **files, int n, int code_option, int max_num) {

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int code_file = 0;
    int counter = 0;
    int all_lines;

    if (code_option == 1) {
        code_file += 1;
    }

    FILE *file;
    for (int i = 0; i < n; ++i) {
        file = fopen(files[i], "r");
        if (file) {
            all_lines += 1;
            while ((read = getline(&line, &len, file)) != -1) {
                if (code_option == 0) {
                    check_line(line, len, pattern); //1 .. 0 -- имя файла .. нет
                } else if (code_option == 1) {
                    check_get_line(line, len, pattern, files[i]); //совпадающие строки
                } else if (code_option == 2) {
                    check_line_counter(line, len, pattern, &counter, 0); //количество совпадающих строк
                } else if (code_option == 3) {
                    options_v(line, len, pattern, &counter, max_num); //несовпадающие строки max_num раз
                } else if (code_option == 4) {
                    check_line_counter(line, len, pattern, &counter, max_num); //совпадающие строки max_num раз
                } else if (code_option == 5) {
                    options_v(line, len, pattern, &counter, 0); // выводит количество несповпадающих строк
                } else if (code_option == 6) { //выводит несовпадающие строки
                    simple_v(line, len, pattern);
                }
            }
            fclose(file);
        }
        if (code_option == 2)
            printf("%d\n", counter);
        if (code_option == 5)
            printf("%d\n", counter);
//            else //TODO
    }
    return 0;
}


const int OP_LEN = 5;

int has_option(char op, const char *options) {
    for (int i = 0; i < OP_LEN; ++i) {
        if (options[i] == op)
            return 1;
    }
    return 0;
}

void other_options(const char *options, int count_options, char *files, int *found_v, int *found_m, int max_num,
                   char *pattern, int count_files) {
    for (int i = 0; i < count_options; ++i) {
        if (options[i] == 'v')
            *found_v = 1; //code_option = 5 выводит количество несовпадающих строк
        if (options[i] == 'm')
            *found_m = 1;
    }
    if (*found_v + *found_m == 2 || *found_m == 1)
        printf("%d\n", max_num);
}

//    options_c();

int count_files1(char *pattern, char **files, const char *options, int count_options, int count_files, int max_num) {
    int found_H = 0, found_c = 0, found_m = 0, found_v = 0, found_h = 0, counter = 0;
    char *const v;

    for (int i = 0; i < count_options; ++i) {
        if (options[i] == 'H') //options_H() //здесь же проверить другие options
            found_H = 1;
        if (options[i] == 'h')
            found_h = 1;
    }
    if (found_H == 0) {
        for (int i = 0; i < count_options; ++i) {
            if (options[i] == 'c')
                found_c = 1;
            if (options[i] == 'v')
                found_v = 1;
            if (options[i] == 'm')
                found_m = 1;
        }
        if (found_c == 1) {
            if (found_v + found_m == 0)
                read_files(pattern, files, count_files, 2, max_num);
            else
                other_options(options, count_options, files, &found_v, &found_m, max_num, pattern, count_files);
        } else if (found_c == 0) {
            if ((found_v == 1) &&
                (found_m == 1)) //проверяет, если found_m = 1, то выводит несовпадающие строки, причем max_num раз
                read_files(pattern, files, count_files, 3, max_num);

            else if ((found_v != 1) && (found_m == 1)) { //code_option = 4
                read_files(pattern, files, count_files, 4, max_num); //выводит совпадающие строки max_num раз
            } else if ((found_v == 1) && (found_m == 0)) //code_option = 6, выводит несовпадающие строки
                read_files(pattern, files, count_files, 6, max_num);
            else
                read_files(pattern, files, count_files, 0, max_num);
        }
    }
    return 0;
}

void grep_command() {
    printf("wrong command\nenter <grep --help> to get more information\n");
}

int wrong_command(char options) {
    if (options == 'm' || options == 'h' || options == 'H' || options == 'c' || options == 'v' || options == '-')
        return 1;
    else
        return 0;
}

void check_errors(long value, const char *argv, const char *num) {
    if (value == 0) {
        if (errno == EINVAL) {
            printf("the command is incorrect\n");
            printf("Conversion error occurred: %d\n", errno);
            exit(1);
        }
    }
    if (strlen(num) != strlen(&argv[1])) {
        printf("the command is incorrect\n");
        printf("the parameter NUM ought to be a number\n");
        exit(2);
    }
}

int main(int argc, char *argv[]) {
    char *pattern = NULL;
    char *files[500]; // TODO
    char options[OP_LEN];
    int count_files = 0;
    int count_options = 0;
    int num = 0;

    for (int i = 1; i < argc; ++i) {
        char *option = argv[i];
        char *num;
        long result;
        if (option[0] == '-') {
            // correct_command
            if (wrong_command(option[1])) {
                printf("wrong command\nenter <grep --help> to get more information\n");
                return 0;
            }
//            read_options() {
//                while () {
//                    switch () {
//                        case -:
//                            waiting_option;
//                        case waiting_option:
//                            read_option
//                    }
//                }
//            }
            if (option[1] == 'm' && !has_option(option[1], options)) {
                options[count_options++] = option[1];
                result = strtol(argv[i + 1], &num, 10);
                check_errors(result, *argv, num);
//                num = atoi(argv[i + 1]); //type of num is int
//                if (!num) {
//                    //TODO: print more detailed error
//                    printf("wrong command\nenter <grep --help> to get more information\n");
//                    return 0;
//                }
                i++;
            } else if (option[1] == 'm' && option[2] != ' ') {
                printf("wrong command\nenter <grep --help> to get more information\n");
                break;
            } else if (!has_option(option[1], options)) {
                printf("%c\n", option[1]);
                options[count_options++] = option[1];
            }
        }

        else if (!pattern) //доделать с && !number(option[0]) для случая -m 200 200
            pattern = argv[i];
        else
            files[count_files++] = argv[i];
    }

    if (count_files == 1) {
        if (count_options == 0) {
            read_files(pattern, files, count_files, 0, num); //options_h
        } else
            // TODO: rename
            count_files1(pattern, files, options, count_options, count_files, num);
    } else if (count_files > 1) {
        if (count_options == 0) {
            read_files(pattern, files, count_files, 1, num);
//                many_files(pattern, files, count_files); //без других options выводит только h и имена файлов
        }
//        /macha/a
//            else
//                option_H(); //проверить другие options
    }

//        else
//            grep_command();
//            printf("wrong command\nenter <grep --help> to get more information");
    //read_files(pattern, files, count_files);
//        grep_command();
    return 0;
}
