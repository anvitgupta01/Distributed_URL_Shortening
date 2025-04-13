#include "HashFunction.h"

unordered_map<string,string> redirect_short_urls;
string save_collison = "fi!#2$@@";

void shorten(string);
void redirect(string);

int main() {
    int t = 1;
    cout << "How many times you would like to test ... " << endl;
    cin >> t;

    while(t--) {
        cout << string(60,'-') << endl;

        string url = ""; // this can be a long_url or a short_url (which is already shortened)
        cout << "Enter the URL to shorten or redirect " << endl;

        cin >> url;

        if (url.find("smallurl.com") != string::npos) {
            redirect(url);
        } else {
            shorten(url);
        }

        cout << string(60,'-') << endl;
    }    

    return 0;
}

void shorten(string long_url) {
    // if long_url has already been processed.
    for (auto e : redirect_short_urls) {
        if (e.second == long_url) {
            cout << "The short url will be ... " << e.first << endl;
            return;
        }
    }

    string hash_value = hashFunction(long_url);
    string short_url = "https://www.smallurl.com/" + hash_value;

    // generated short_url already present for some other webpage. Hash collision.
    string temp = long_url;
    while(redirect_short_urls.find(short_url) != redirect_short_urls.end()) {
        temp += save_collison;
        hash_value = hashFunction(temp);
        short_url = "https://www.smallurl.com/" + hash_value;
    }

    redirect_short_urls[short_url] = long_url;

    cout << "The short url will be ... " << short_url << endl;
}

void redirect(string short_url) {
    if (redirect_short_urls.find(short_url) != redirect_short_urls.end()) {
        cout << "Redirecting to " << redirect_short_urls[short_url] << endl;
    } else {
        cout << "[ERROR - 404]: Page Not Found." << endl;
    }
}