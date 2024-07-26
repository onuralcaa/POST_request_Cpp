#include <curl/curl.h>
#include <iostream>
#include <fstream>

bool uploadImage(const std::string& url, const std::string& imagePath) {
    CURL *curl;
    CURLcode res;
    curl_mime *form = nullptr;
    curl_mimepart *field = nullptr;
    bool success = false;

    // Initialize CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        // Initialize the form
        form = curl_mime_init(curl);

        // Add the file field
        field = curl_mime_addpart(form);
        curl_mime_name(field, "file");
        curl_mime_filedata(field, imagePath.c_str());

        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the form data
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

        // Enable verbose output for debugging
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Set timeout options
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);

        // Perform the request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            if (response_code == 200) {
                success = true;
            } else if (response_code == 404) {
                std::cerr << "Error 404: Not Found. The requested URL was not found on the server." << std::endl;
            } else {
                std::cerr << "Failed to upload the image. Status code: " << response_code << std::endl;
            }
        }

        // Clean up
        curl_mime_free(form);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return success;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <url> <path to image.jpg>" << std::endl;
        return 1;
    }

    std::string url = argv[1];
    std::string imagePath = argv[2];

    if (uploadImage(url, imagePath)) {
        std::cout << "Upload is done." << std::endl;
    }

    return 0;
}
