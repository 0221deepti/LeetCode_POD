 int compareVersion(string version1, string version2) {
 stringstream ss1(version1);
    stringstream ss2(version2);
    vector<int> ver1;
    vector<int> ver2;

    // Parsing version 1
    string token;
    while (getline(ss1, token, '.')) {
        ver1.push_back(stoi(token));
    }

    // Parsing version 2
    while (getline(ss2, token, '.')) {
        ver2.push_back(stoi(token));
    }

    // Pad the shorter version with zeros
    int max_size = max(ver1.size(), ver2.size());
    ver1.resize(max_size, 0);
    ver2.resize(max_size, 0);

    // Comparing versions
    for (int i = 0; i < max_size; i++) {
        if (ver1[i] > ver2[i]) {
            return 1;
        } else if (ver1[i] < ver2[i]) {
            return -1;
        }
    }

    return 0; // Versions are equal
}
