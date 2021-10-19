#include <bits/stdc++.h>

using namespace std;

//Считывание сообщения

string read_message() {
    string s;
    getline(cin, s);
    return s;
}

//Проверка строки на правильность

bool check_string(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            s.erase(s.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1') {
            return 0;
        }
    }

    if (s.length() > 7 || s.length() < 7) {
        return 0;
    }
    return 1;
}

// Вывод и исправление неправильных битов

void wrong_par_bit(int bit_index, vector<int>& par_arr) {
    cout << bit_index << " parity bit is wrong\n";
}

void wrong_inf_bit(int bit_index, vector<int>& inf_arr) {
    cout << bit_index << " information bit is wrong\n";
    inf_arr[bit_index - 1] = !inf_arr[bit_index - 1];
}

int main()
{
    vector<int> par_bits, inf_bits, message;

    string mes;

    //Считываем правильную строку

    getline(cin, mes);

    while (!check_string(mes)) {
        cout << "Wrong message\nTry again: ";
        mes = read_message();
        cout << '\n';
    }

    //Разделение информационных и проверочных битов
    for (int i = 0; i < mes.size(); i++) {
        int number = int(mes[i] - '0');

        double check_par_bit = log2(i + 1);

        if (check_par_bit == ceil(check_par_bit))
            par_bits.push_back(number);
        else {
            inf_bits.push_back(number);
        }

        message.push_back(number);
    }

    // Считаем синдромы

    int syndrome1 = par_bits[0] ^ inf_bits[0] ^ inf_bits[1] ^ inf_bits[3];
    int syndrome2 = par_bits[1] ^ inf_bits[0] ^ inf_bits[2] ^ inf_bits[3];
    int syndrome3 = par_bits[2] ^ inf_bits[1] ^ inf_bits[2] ^ inf_bits[3];

    int sum = syndrome1 + (syndrome2 * 2) + (syndrome3 * 4);

    // Определение ошибки

    if (sum == 0) {
        cout << "No problem\n";
    } else {
        double check = log2(sum);
        if (check == ceil(check)) {
            wrong_par_bit(check + 1, par_bits);
        } else {
            int index;
            if (sum == 3)
                index = 1;
            else
                index = sum - 3;
            wrong_inf_bit(index, inf_bits);
        }
    }

    //Вывод правильного сообщения

    cout << "right message is ";
    for (int i = 0; i < inf_bits.size(); i++) {
        cout << inf_bits[i];
    }
    cout << endl;


    return 0;
}
