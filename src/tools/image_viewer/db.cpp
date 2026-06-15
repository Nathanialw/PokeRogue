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

int UpdateImagePath(const std::string& image_path, const std::string& entity_name, const EntityTypes& entity_type) {
    // 1. Open the database
    sqlite3* db = nullptr;
    // Use SQLITE_OPEN_READWRITE to ensure we can modify the DB.
    // sqlite3_open defaults to READWRITE|CREATE, which is usually fine if the file exists.
    int rc = sqlite3_open(db_path.c_str(), &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return rc;
    }

    // 2. Construct the SQL query with placeholders (?)
    // Correct Syntax: UPDATE table SET column = ? WHERE column = ?
    std::string table = image_tables[entity_type];
    std::string sql = "UPDATE " + table + " SET image = ? WHERE name = ?";

    sqlite3_stmt* stmt = nullptr;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return rc;
    }

    // 3. Bind the parameters
    // Bind index 1: The image path (TEXT)
    rc = sqlite3_bind_text(stmt, 1, image_path.c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        std::cerr << "Bind path failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    // Bind index 2: The entity name (TEXT)
    rc = sqlite3_bind_text(stmt, 2, entity_name.c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        std::cerr << "Bind name failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    // 4. Execute the statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // SQLITE_ROW means it returned data (unlikely for UPDATE), SQLITE_DONE means success
        std::cerr << "Execution failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return rc;
    }

    // Optional: Check if any rows were actually updated
    if (sqlite3_changes(db) == 0) {
        std::cerr << "Warning: No rows updated. Entity name might not exist.\n";
    }

    // 5. Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return SQLITE_OK;
}





#include <string>


std::string GetImagePath(const std::string& entity_name, const EntityTypes& entity_type)
{
    sqlite3* db = nullptr;
    std::string image;

    int rc = sqlite3_open(db_path.c_str(), &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Cannot open database: " << (db ? sqlite3_errmsg(db) : "out of memory") << '\n';
        sqlite3_close(db);
        return image;
    }

    std::string select = "SELECT image FROM " + image_tables[entity_type] + " WHERE name = ?";
    sqlite3_stmt* stmt = nullptr;
    rc = sqlite3_prepare_v2(db, select.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Prepare failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        return image;
    }

    rc = sqlite3_bind_text(stmt, 1, entity_name.c_str(), -1, SQLITE_STATIC);
    if (rc != SQLITE_OK) {
        std::cerr << "Bind name failed: " << sqlite3_errmsg(db) << '\n';
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return image;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text)
            image = reinterpret_cast<const char*>(text);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return image;
}
