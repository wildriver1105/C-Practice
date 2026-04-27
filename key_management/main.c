#include "key_manager.h"

int main() {
    KeyStorage *my_storage = init_storage(2);

    add_key(my_storage, 101, "AWS_ROOT", "AKIA-XXXX-YYYY");
    add_key(my_storage, 102, "GITHUB_TOKEN", "ghp_secure_token_123");

    add_key(my_storage, 103, "DB_PASSWORD", "db_pass_5678");

    print_all_keys(my_storage);

    saveKeyFile(*my_storage);

    free_storage(my_storage);

    return 0;
}