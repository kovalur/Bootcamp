#include <stdio.h>

#define FARMERQUANTITY 1001

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int farmerQuantity, amountNeeded;
    unsigned long long amounts[FARMERQUANTITY];
    unsigned long long prices[FARMERQUANTITY];
    unsigned long long minPrice = 0;
    unsigned long long lowestPrice, highestPrice, price;
    
    fscanf(in, "%d", &farmerQuantity);
    fscanf(in, "%d", &amountNeeded);
    
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%llu %llu", &amounts[i], &prices[i]);
    }
    fclose(in);

    lowestPrice = prices[0];
    highestPrice = prices[0];
    for ( int i = 0; i < farmerQuantity; i++ ) {
        if ( prices[i] < lowestPrice ) {
            lowestPrice = prices[i];
        }
        if ( prices[i] > highestPrice ) {
            highestPrice = prices[i];
        }
    }

    price = lowestPrice;
    for ( int i = 0; i < farmerQuantity && price <= highestPrice && amountNeeded > 0; i++ ) {
        for ( int j = 0; j < farmerQuantity && amountNeeded > 0; j++ ) {
            if ( prices[j] == price ) {
                if ( amountNeeded >= amounts[j] ) {
                    amountNeeded = amountNeeded - amounts[j];
                    minPrice = minPrice + price * amounts[j];
                } else {
                    minPrice = minPrice + price * amountNeeded;
                    amountNeeded = 0;
                }
            }
        }
        price += 1;
    }
    
    if ( amountNeeded != 0 ) {
        minPrice = 0;
    }
    
    fprintf(out, "%llu\n", minPrice);
    fclose(out);
    
    return 0;
}

/*
Задача milk

Условие задачи
Молочная компания каждый день покупает молоко у фермеров. У каждого из
<farmerQuantity> фермеров есть <amount> литров молока по цене <price>. Найти
минимальную стоимость <minPrice>, за которую возможно приобрести <amountNeeded>
литров молока. В случае, если у фермеров недостаточно молока, вывести в качестве
<minPrice> значение 0.

В файле task.in заданы целые числа:
<farmerQuantity> <amountNeeded>
<amount1> <price1>
<amount2> <price2>
.....
<amountN> <priceN>

Вывести minPrice в task.out.

Ограничения:
0 <= farmerQuantity <= 100 000 000
0 <= amountNeeded <= 300 000 000
0 <= amount <= 300 000 000
1 <= price <= 1 000

Пример ввода
3 10
5 1
8 2
8 3
Пример вывода
15
*/
