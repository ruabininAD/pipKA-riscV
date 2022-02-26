
#include <iostream>
#include <string>
using namespace std;

class Remember {

    int init_value[32];//поступаюшие значения
    string regist[32] = {"x0(zero)", "x1(ra) ", "x2(sp) ", "x3(gp) ", "x4(tp) ", "x5(t0) ", "x6(t1) ", "x7(t2) ", "x8(s0/fp) ", "x9(s1) ", "x10(a0) ", "x11(a1) ", "x12(a2) ", "x13(a3) ",
              "x14(a4) ", "x15(a5) ", "x16(a6) ", "x17(a7) ", "x18(a2) ", "x19(a3) ", "x20(aa4) ", "x21(s5) ", "x22(s6) ", "x23(s7) ", "x24(s8) ", "x25(s9) ", "x26(s10) ", "x27(s11) ",
             "x28(t3) ", "x29(t4) ", "x30(t5) ", "x31(t6) "}; //номер регистра
    int decimal[32]; //десятичное значение в регистре

public:
    Remember() {
        for( int count = 0; count < 32; count++){
            init_value[count] = 0; /* regist[count] = 0;*/  decimal[count] = 0;
        }
    }
    // спецификатор доступа
    void message(int n) { // функция (метод класса) выводящая ячейку на экран
        cout << init_value[n] <<"  "<< regist[n] <<"  "<< decimal[n] << endl;
    }
    void all_cell() { // функция (метод класса) выводящая все  ячейки на экран
        for ( int count = 0; count < 32; count++){
            cout << count <<"|   "<< init_value[count] <<"  "<< regist[count] <<"  "<< decimal[count] << endl;
        }
    }
    void record_init_value(int location, float value) { // функция (метод класса) записывающая значение в ячейку входа
        init_value[location] = value;
    }
    void record_decimal_value(int location, float value) { // функция (метод класса) записывающая значение в ячейку входа
        decimal[location] = value;
    }
    int get_init(int location){
        return init_value[location];
    }
    int get_value(int location){
        return decimal[location];
    }

};

class Instrucions:Remember{

    public:
        void add(string local_result, string local_a, string local_b, Remember& obj){//ссылка на объект
            //a+b = result
            // c record in decimal[local_record]
            local_a = local_a[local_a.size()-1];//обрезаем буквы
            local_b = local_b[local_b.size()-1];
            local_result = local_result[local_result.size()-1];

            int result = obj.get_init(stoi(local_b)) + obj.get_init(stoi(local_a));
            cout << obj.get_init(stoi(local_b)) << " + "<< obj.get_init(stoi(local_a))<<" = "<<result << endl;
            obj.record_decimal_value(stoi(local_result), result);
        }

        void sub(string local_result, string local_a, string local_b, Remember& obj) {//вычитатние
            // a - b = result
            local_a = local_a[local_a.size()-1];//обрезаем буквы
            local_b = local_b[local_b.size()-1];
            local_result = local_result[local_result.size()-1];
            int result = obj.get_init(stoi(local_a)) - obj.get_init(stoi(local_b));
            cout << obj.get_init(stoi(local_b)) << " - "<< obj.get_init(stoi(local_a))<<" = "<<result << endl;
            obj.record_decimal_value(stoi(local_result), result);


        }


};

int main() {
    Remember remember; // создание объекта класса ПАМЯТЬ
    Instrucions instrucions;

    remember.record_init_value(1, 811);
    remember.record_init_value(2, 822);
    //remember.record_init_value(3, 3);
    //remember.record_init_value(5, 1);

    cout << endl;


    instrucions.add("x3","x2","x1", remember);
    remember.all_cell();
    instrucions.sub("x4", "x2", "x1", remember);
    remember.all_cell();
    return 0;
}
