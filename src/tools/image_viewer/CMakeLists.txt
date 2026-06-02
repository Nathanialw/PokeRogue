add_executable(ImageViewer
        main.cpp
        init.cpp
        input.cpp
        rendering.cpp
        update.cpp
        images.cpp
        db.cpp
        globals.cpp

        constants.h
        ui.cpp
        ui.h
        text.cpp
        text.h
        tile_map_preview.cpp
        tile_map_preview.h
)


target_include_directories(ImageViewer PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)


target_link_libraries(ImageViewer PRIVATE
        SDL3
        SDL3_image
        SDL3_ttf
        stdc++
        sqlite3
)