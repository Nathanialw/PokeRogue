//
// Created by nathanial on 5/31/26.
//

#include "db.h"

#include <iostream>
#include "sqlite3.h"

/*
 *
 */
int GetImageFolders(std::vector<std::string>& image_folders, uint16_t& entity_count, const EntityTypes& entity_type)
{
    // 1. Open the database (must already exist)
    sqlite3* db = nullptr;
    int rc = sqlite3_open(db_path.c_str(), &db);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return rc;
    }

    std::string select = "SELECT name FROM ";
    std::string table = image_tables[entity_type];
    select += table;

    // 2. Prepare a statement with a placeholder (?)
    sqlite3_stmt* stmt = nullptr;
    rc = sqlite3_prepare_v2(db, select.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return rc;
    }

    // 3. Bind the parameter (e.g., id = 1)
    sqlite3_bind_int(stmt, 1, 1); // first placeholder gets value 1

    // 4. Execute the statement and fetch the result
    rc = sqlite3_step(stmt);
    while (rc == SQLITE_ROW)
    {
        // 5. Retrieve each string column
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text)
        {
            image_folders.push_back(std::string((char*)text));
            entity_count++;
        }
        rc = sqlite3_step(stmt);
    }

    // 6. Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}
