int main(int argc, char** argv) {
  char *userAndFile = argv[2];
  
  {
    char fileBuffer[PATH_MAX];
    snprintf(fileBuffer, sizeof(fileBuffer), "/home/%s", userAndFile);
    // BAD: a string from the user is used in a filename extended and security-and-quality https://codeql.github.com/codeql-query-help/cpp/cpp-path-injection/
    fopen(fileBuffer, "wb+");
  }
}

bool checkOverflow(unsigned short x, unsigned short y) {
  // BAD: comparison is always false due to type promotion https://codeql.github.com/codeql-query-help/cpp/cpp-bad-addition-overflow-check/
  return (x + y < x);  
}
