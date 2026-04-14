#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <thread>
#include <string>

int main() {

    std::cout << "\n--- ZADANIE 1: std::async i std::future ---\n\n";

    // ZADANIE 1:
    // U¿yj std::async z wymuszeniem std::launch::async, aby znaleŸæ najwiêksz¹ 
    // liczbê w wektorze 'dane'. Odbierz wynik za pomoc¹ obiektu std::future 
    // i wyœwietl go. 

    std::vector<int> dane = { 15, 42, 7, 99, 23 };

  

    std::cout << "\nOczekiwany wynik: Najwieksza liczba to 99\n";


    std::cout << "\n\n--- ZADANIE 2: Polityki uruchomieniowe ---\n\n";

    // ZADANIE 2:
    // Poni¿sza funkcja zwraca identyfikator w¹tku, w którym zosta³a uruchomiona.
    // 1. Zleæ jej wykonanie do 'bilet_async' u¿ywaj¹c flagi std::launch::async.
    // 2. Zleæ jej wykonanie do 'bilet_defer' u¿ywaj¹c flagi std::launch::deferred.
    // 3. Odbierz oba wyniki za pomoc¹ .get() i wyœwietl je.

    auto sprawdz_moje_id = []() {
        return std::this_thread::get_id();
    };
    
    std::cout << "ID Watku Glownego (main): " << std::this_thread::get_id() << "\n\n";



    std::cout << "\nOczekiwany wynik:\n";
    std::cout << "Watek async powinien miec inne id niz watek glowny.\n";
    std::cout << "Watek deferred powinien miec takie samo id jak watek glowny.\n";


    std::cout << "\n--- ZADANIE 3: std::promise ---\n\n";

    // ZADANIE 3:
    // Oblicz sume elementow wektora 'liczby' w osobnym watku
    // i odbierz wynik w main za pomoca std::promise.

    std::vector<int> liczby = { 3, 7, 2, 8, 5 };

    std::cout << "\nOczekiwany wynik: 25\n";

    std::cout << "\n\n--- ZADANIE 4: std::packaged_task & reset ---\n\n";

    // ZADANIE 4:
    // Owin 'czy_pierwsza' w packaged_task i wykonaj asynchronicznie dla 17 i 18.
    // Uzyj reset() do ponownego uzycia tego samego obiektu.
    // Wyswietl oba wyniki jako Tak/Nie.

    auto czy_pierwsza = [](int n) -> bool {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    };

    std::cout << "\nOczekiwany wynik:\n";
    std::cout << "Czy 17 to liczba pierwsza? -> Tak\n";
    std::cout << "Czy 18 to liczba pierwsza? -> Nie\n";

    return 0;
}