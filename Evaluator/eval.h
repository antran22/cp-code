// Copyrighted by annie-chan
#pragma once
#include <bits/stdc++.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#define whole(x) x.begin(), x.end()
#define sz(x) (static_cast <int> (x.size()))
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
std::string get_current_dir();
bool init(std::string current_dir);
void clean_up(std::string current_dir);
void move_file_to_temp(std::string test_name, std::string problem);
