#include <iostream>
#include <cmath>

using namespace std;

/** 
 * @class Vector3
 * @brief La clase Vector3 representa vectores de tres componentes (x, y, z).
 */
class Vector3 {
public:
    /** 
     * @brief Constructor por defecto.
     * @param x Componente x del vector. Valor por defecto es 0.0.
     * @param y Componente y del vector. Valor por defecto es 0.0.
     * @param z Componente z del vector. Valor por defecto es 0.0.
     */
    Vector3(double x = 0.0, double y = 0.0, double z = 0.0){

        (*this).x = x;
        (*this).y = y;
        (*this).z = z;

    }

    /** 
     * @brief Suma de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante de la suma.
     */
    static Vector3 add(const Vector3& u, const Vector3& v){

        Vector3 result = Vector3(u.x + v.x, u.y + v.y, u.z + v.z);

        return result;
    }


    /**
     * @brief Sobrecarga del operador += para sumar otro vector a este vector.
     * @param v El vector a sumar.
     * @return Referencia al vector resultante después de la suma.
     */
    Vector3& operator+=(const Vector3& v) {

        Vector3* result = new Vector3;

        Vector3 suma = v.add((*this),v);

        *result = suma ;

        return (*result);
    }


    /** 
     * @brief Clona el vector actual.
     * @return Copia del vector actual.
     */
    Vector3 clone() const{

        Vector3 clon = Vector3((*this).x,(*this).y,(*this).z);

        return clon;

    }

    /** 
     * @brief Producto cruz de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante del producto cruz.
     */
    static Vector3 cross(const Vector3& u, const Vector3& v){

        double cross_x = (u.y)*(v.z) - (u.z)*(v.y);
        double cross_y = (u.z)*(v.x) - (u.x)*(v.z);
        double cross_z = (u.x)*(v.y) - (u.y)*(v.x);

        Vector3 cross_vector = Vector3(cross_x,cross_y,cross_z);

        return cross_vector;
    }

    /** 
     * @brief Distancia euclidiana entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Distancia euclidiana entre los vectores.
     */
    static double distance(const Vector3& u, const Vector3& v){

        double power_2_x = (v.x-u.x)*(v.x-u.x);
        double power_2_y = (v.y-u.y)*(v.y-u.y);
        double power_2_z = (v.z-u.z)*(v.z-u.z);

        double distance = sqrt(power_2_x + power_2_y + power_2_z);

        return distance;
    }

    /** 
     * @brief Producto punto de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Producto punto de los vectores.
     */
    static double dot(const Vector3& u, const Vector3& v){

        double producto = (u.x*v.x)+(u.y*v.y)+(u.z*v.z);

        return producto;
    }

    /** 
     * @brief Comprueba si dos vectores son aproximadamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @param epsilon Tolerancia para la comparación. Valor por defecto es 0.000001.
     * @return Verdadero si los vectores son aproximadamente iguales.
     */
    static bool equals(const Vector3& u, const Vector3& v, double epsilon = 0.000001){

        bool x_comparation = (abs(u.x-v.x))<epsilon;
        bool y_comparation = (abs(u.y-v.y))<epsilon;
        bool z_comparation = (abs(u.z-v.z))<epsilon;

        bool result = x_comparation && y_comparation && z_comparation;

        return result;
    }

    /** 
     * @brief Comprueba si dos vectores son exactamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Verdadero si los vectores son exactamente iguales.
     */
    static bool exactEquals(const Vector3& u, const Vector3& v){

        bool x_comparation = u.x==v.x;
        bool y_comparation = u.y==v.y;
        bool z_comparation = u.z==v.z;

        bool result = x_comparation && y_comparation && z_comparation;

        return result;
    }

    /** 
     * @brief Normaliza el vector actual.
     * @return Vector normalizado.
     */
    Vector3 normalize() const{

        Vector3 zero = Vector3();

        double norma = Vector3::distance(*this,zero);

        double x_coor =(*this).x / norma;
        double y_coor =(*this).y / norma;
        double z_coor =(*this).z / norma;

        Vector3 normalized_vector = Vector3(x_coor,y_coor,z_coor);

    }

    /** 
     * @brief Asigna nuevos valores al vector.
     * @param x Componente x del vector. Valor por defecto es 0.0.
     * @param y Componente y del vector. Valor por defecto es 0.0.
     * @param z Componente z del vector. Valor por defecto es 0.0.
     */
    void set(double x = 0.0, double y = 0.0, double z = 0.0){

        (*this).x = x;
        (*this).y = y;
        (*this).z = z;

    }

    /** 
     * @brief Resta dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector resultante de la resta.
     */
    static Vector3 subtract(const Vector3& u, const Vector3& v){

        Vector3 result = Vector3(u.x - v.x, u.y - v.y, u.z - v.z);

        return result;
    }

    /** 
     * @brief Distancia euclidiana al cuadrado entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Distancia euclidiana al cuadrado entre los vectores.
     */
    static double squaredDistance(const Vector3& u, const Vector3& v){

        double power_2_x = (v.x-u.x)*(v.x-u.x);
        double power_2_y = (v.y-u.y)*(v.y-u.y);
        double power_2_z = (v.z-u.z)*(v.z-u.z);

        double distance = power_2_x + power_2_y + power_2_z;

        return distance;
    }

    /** 
     * @brief Asigna el vector a cero.
     */
    void zero(){
        (*this).set();
    }

public:
    double x, y, z;
};

/** 
 * @class Vector4
 * @brief La clase Vector4 representa vectores de tres componentes (x, y, z, w).
 */
class Vector4 {
public:
    double x, y, z, w;

    /**
     * @brief Constructor que inicializa los componentes del vector.
     * @param x Componente x del vector (por defecto 0).
     * @param y Componente y del vector (por defecto 0).
     * @param z Componente z del vector (por defecto 0).
     * @param w Componente w del vector (por defecto 0).
     */
    Vector4(double x = 0, double y = 0, double z = 0, double w = 0) : x(x), y(y), z(z), w(w) {}

    /**
     * @brief Devuelve la suma de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector4 Resultado de la suma de u y v.
     */
    static Vector4 add(const Vector4& u, const Vector4& v){

        double added_x = u.x + v.x;
        double added_y = u.y + v.y;
        double added_z = u.z + v.z;
        double added_w = u.w + v.w;

        Vector4 added = Vector4(added_x,added_y,added_z,added_w);

        return added;
    }

    /**
     * @brief Devuelve una copia del objeto Vector4.
     * @return Vector4 Copia del objeto actual.
     */
    Vector4 clone() const{
        Vector4 clone = Vector4((*this).x,(*this).y,(*this).z,(*this).w);
        return clone;
    }

    /**
     * @brief Devuelve la distancia euclidiana entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Distancia euclidiana entre u y v.
     */
    static double distance(const Vector4& u, const Vector4& v){

        double x_term = (v.x-u.x)*(v.x-u.x);
        double y_term = (v.y-u.y)*(v.y-u.y);
        double z_term = (v.z-u.z)*(v.z-u.z);
        double w_term = (v.w-u.w)*(v.w-u.w);

        double distance = sqrt(x_term + y_term + z_term + w_term);
        return distance;
    }

    /**
     * @brief Devuelve el producto punto de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Producto punto de u y v.
     */
    static double dot(const Vector4& u, const Vector4& v){

        double x_term = v.x*u.x;
        double y_term = v.y*u.y;
        double z_term = v.z*u.z;
        double w_term = v.w*u.w;

        double dot = x_term + y_term + z_term + w_term;

        return dot;

    }

    /**
     * @brief Verifica si dos vectores son aproximadamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @param epsilon Tolerancia para la comparación (por defecto 0.000001).
     * @return bool True si los vectores son aproximadamente iguales, false en caso contrario.
     */
    static bool equals(const Vector4& u, const Vector4& v, double epsilon = 0.000001){

        bool x_comparation = (abs(u.x-v.x))<epsilon;
        bool y_comparation = (abs(u.y-v.y))<epsilon;
        bool z_comparation = (abs(u.z-v.z))<epsilon;
        bool w_comparation = (abs(u.w-v.w))<epsilon;

        bool result = x_comparation && y_comparation && z_comparation && w_comparation;

        return result;
    }

    /**
     * @brief Verifica si dos vectores son exactamente iguales.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return bool True si los vectores son exactamente iguales, false en caso contrario.
     */
    static bool exactEquals(const Vector4& u, const Vector4& v){

        bool x_comparation = u.x==v.x;
        bool y_comparation = u.y==v.y;
        bool z_comparation = u.z==v.z;
        bool w_comparation = u.w==v.w;

        bool result = x_comparation && y_comparation && z_comparation && w_comparation;

        return result;
    }

    /**
     * @brief Devuelve el vector normalizado.
     * @return Vector4 Vector normalizado.
     */
    Vector4 normalize() const{

        Vector4 zero = Vector4();

        double norm = distance(zero,(*this));

        Vector4 normalize_vector = Vector4((*this).x / norm,(*this).y / norm,(*this).z / norm,(*this).w / norm);

        return normalize_vector;
    }

    /**
     * @brief Asigna nuevos valores a los componentes del vector.
     * @param x Nuevo valor para el componente x.
     * @param y Nuevo valor para el componente y.
     * @param z Nuevo valor para el componente z.
     * @param w Nuevo valor para el componente w.
     */
    void set(double x = 0.0, double y = 0.0, double z = 0.0, double w = 0.0){

        (*this).x = x;
        (*this).y = y;
        (*this).z = z;
        (*this).w = w;

    }

    /**
     * @brief Devuelve la resta de dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return Vector4 Resultado de la resta de u y v.
     */
    static Vector4 subtract(const Vector4& u, const Vector4& v){
        Vector4 resta = Vector4(u.x-v.x,u.y-v.y,u.z-v.z,u.w-v.w);
        return resta;
    }

    /**
     * @brief Devuelve la distancia euclidiana al cuadrado entre dos vectores.
     * @param u Primer vector.
     * @param v Segundo vector.
     * @return double Distancia euclidiana al cuadrado entre u y v.
     */
    static double squaredDistance(const Vector4& u, const Vector4& v){
        
        double x_term = (v.x-u.x)*(v.x-u.x);
        double y_term = (v.y-u.y)*(v.y-u.y);
        double z_term = (v.z-u.z)*(v.z-u.z);
        double w_term = (v.w-u.w)*(v.w-u.w);

        double distance = x_term + y_term + z_term + w_term;

        return distance;
    }

    /**
     * @brief Asigna cero a cada componente del vector.
     */
    void zero(){
        (*this).set();
    }
};



/** 
 * @class Matrix3
 * @brief La clase Matrix3 representa matrices de 3 × 3 y se utiliza para la representación y construcción de transformaciones en dos dimensiones.
 */
class Matrix3 {
public:
    double a00, a01, a02;
    double a10, a11, a12;
    double a20, a21, a22;

    /** 
     * @brief Constructor por defecto.
     * @param a00 Elemento en la posición (0,0). Valor por defecto es 1.
     * @param a01 Elemento en la posición (0,1). Valor por defecto es 0.
     * @param a02 Elemento en la posición (0,2). Valor por defecto es 0.
     * @param a10 Elemento en la posición (1,0). Valor por defecto es 0.
     * @param a11 Elemento en la posición (1,1). Valor por defecto es 1.
     * @param a12 Elemento en la posición (1,2). Valor por defecto es 0.
     * @param a20 Elemento en la posición (2,0). Valor por defecto es 0.
     * @param a21 Elemento en la posición (2,1). Valor por defecto es 0.
     * @param a22 Elemento en la posición (2,2). Valor por defecto es 1.
     */
    Matrix3(double a00 = 1, double a01 = 0, double a02 = 0,
            double a10 = 0, double a11 = 1, double a12 = 0,
            double a20 = 0, double a21 = 0, double a22 = 1){

                (*this).a00 = a00;
                (*this).a10 = a10;
                (*this).a20 = a20;

                (*this).a01 = a01;
                (*this).a11 = a11;
                (*this).a21 = a21;

                (*this).a02 = a02;
                (*this).a12 = a12;
                (*this).a22 = a22;

            }

    /** 
     * @brief Suma de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la suma.
     */
    static Matrix3 add(const Matrix3& m1, const Matrix3& m2){

        Matrix3 suma = Matrix3( m1.a00+m2.a00, m1.a01+m2.a01, m1.a02+m2.a02,
                                m1.a10+m2.a10, m1.a11+m2.a11, m1.a12+m2.a12, 
                                m1.a20+m2.a20, m1.a21+m2.a21, m1.a22+m2.a22);
        
        return suma;
    }

    /** 
     * @brief Calcula la matriz adjoint.
     * @return Matriz adjoint.
     */
    Matrix3 adjoint() const{
        double m00 = ((*this).a11*(*this).a22)-((*this).a12*(*this).a21);
        double m01 = -(((*this).a01*(*this).a22)-((*this).a02*(*this).a21));
        double m02 = ((*this).a01*(*this).a12)-((*this).a02*(*this).a11);

        double m10 = -(((*this).a10*(*this).a22)-((*this).a12*(*this).a20));
        double m11 = ((*this).a00*(*this).a22)-((*this).a02*(*this).a20);
        double m12 = -(((*this).a00*(*this).a12)-((*this).a02*(*this).a10));

        double m20 = ((*this).a10*(*this).a21)-((*this).a11*(*this).a20);
        double m21 = -(((*this).a00*(*this).a21)-((*this).a01*(*this).a20));
        double m22 = ((*this).a00*(*this).a11)-((*this).a01*(*this).a10);

        Matrix3 adjoint = Matrix3(m00, m01, m02, m10, m11, m12, m20, m21, m22);

        return adjoint ;

    }

    /** 
     * @brief Clona la matriz actual.
     * @return Copia de la matriz actual.
     */
    Matrix3 clone() const{
        Matrix3 clone = Matrix3((*this).a00, (*this).a01, (*this).a02, (*this).a10, (*this).a11, (*this).a12, (*this).a20, (*this).a21, (*this).a22);

        return clone;
    }

    /** 
     * @brief Calcula el determinante de la matriz.
     * @return Determinante de la matriz.
     */
    double determinant() const{

        long double suma  = ((*this).a00*(*this).a11*(*this).a22) + ((*this).a01*(*this).a12*(*this).a20) + ((*this).a02*(*this).a10*(*this).a21);
        long double resta =  ((*this).a20*(*this).a11*(*this).a02) + ((*this).a21*(*this).a12*(*this).a00) + ((*this).a22*(*this).a10*(*this).a01);
        long double det = suma - resta;

        return det;
    }

    /** 
     * @brief Compara dos matrices con un epsilon.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @param e Epsilon para la comparación.
     * @return Verdadero si las matrices son aproximadamente iguales.
     */
    static bool equalsWithE(const Matrix3& m1, const Matrix3& m2, double e);

    /** 
     * @brief Compara dos matrices con un epsilon predeterminado.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Verdadero si las matrices son aproximadamente iguales.
     */
    static bool equals(const Matrix3& m1, const Matrix3& m2);

    /** 
     * @brief Compara dos matrices exactamente.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Verdadero si las matrices son exactamente iguales.
     */
    static bool exactEquals(const Matrix3& m1, const Matrix3& m2);

    /** 
     * @brief Asigna la matriz a la matriz identidad.
     */
    void identity();

    /** 
     * @brief Calcula la inversa de la matriz.
     * @return Matriz inversa.
     */
    Matrix3 invert() const;

    /** 
     * @brief Multiplica dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la multiplicación.
     */
    static Matrix3 multiply(const Matrix3& m1, const Matrix3& m2);

    /** 
     * @brief Multiplica una matriz por un escalar.
     * @param m1 Matriz a multiplicar.
     * @param c Escalar.
     * @return Matriz resultante de la multiplicación por el escalar.
     */
    static Matrix3 multiplyScalar(const Matrix3& m1, double c);

    /** 
     * @brief Multiplica una matriz por un vector.
     * @param v Vector a multiplicar.
     * @return Vector resultante de la multiplicación.
     */
    Vector3 multiplyVector(const Vector3& v) const;

    /** 
     * @brief Crea una matriz de rotación.
     * @param theta Ángulo de rotación en radianes.
     * @return Matriz de rotación.
     */
    static Matrix3 rotate(double theta);

    /** 
     * @brief Crea una matriz de escalamiento.
     * @param sx Factor de escala en el eje x.
     * @param sy Factor de escala en el eje y.
     * @return Matriz de escalamiento.
     */
    static Matrix3 scale(double sx, double sy);

    /** 
     * @brief Asigna nuevos valores a la matriz.
     * @param a00 Elemento en la posición (0,0).
     * @param a01 Elemento en la posición (0,1).
     * @param a02 Elemento en la posición (0,2).
     * @param a10 Elemento en la posición (1,0).
     * @param a11 Elemento en la posición (1,1).
     * @param a12 Elemento en la posición (1,2).
     * @param a20 Elemento en la posición (2,0).
     * @param a21 Elemento en la posición (2,1).
     * @param a22 Elemento en la posición (2,2).
     */
    void set();

    /** 
     * @brief Resta dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matriz resultante de la resta.
     */
    static Matrix3 subtract(const Matrix3& m1, const Matrix3& m2);

    /** 
     * @brief Crea una matriz de translación.
     * @param tx Desplazamiento en el eje x.
     * @param ty Desplazamiento en el eje y.
     * @return Matriz de translación.
     */
    static Matrix3 translate(double tx, double ty);

    /** 
     * @brief Calcula la transpuesta de la matriz.
     * @return Matriz transpuesta.
     */
    Matrix3 transpose() const;
};


/** 
 * @class Matrix4
 * @brief La clase Matrix4 representa matrices de 4 × 4 y se utiliza para la representación y construcción de transformaciones en tres dimensiones.
 */
class Matrix4 {
public:
    double a00, a01, a02, a03;
    double a10, a11, a12, a13;
    double a20, a21, a22, a23;
    double a30, a31, a32, a33;

    /**
     * @brief Constructor que inicializa una matriz 4x4 con valores por defecto.
     * @param a00 Valor para el elemento (0,0).
     * @param a01 Valor para el elemento (0,1).
     * @param a02 Valor para el elemento (0,2).
     * @param a03 Valor para el elemento (0,3).
     * @param a10 Valor para el elemento (1,0).
     * @param a11 Valor para el elemento (1,1).
     * @param a12 Valor para el elemento (1,2).
     * @param a13 Valor para el elemento (1,3).
     * @param a20 Valor para el elemento (2,0).
     * @param a21 Valor para el elemento (2,1).
     * @param a22 Valor para el elemento (2,2).
     * @param a23 Valor para el elemento (2,3).
     * @param a30 Valor para el elemento (3,0).
     * @param a31 Valor para el elemento (3,1).
     * @param a32 Valor para el elemento (3,2).
     * @param a33 Valor para el elemento (3,3).
     */
    Matrix4(
        double a00 = 1, double a01 = 0, double a02 = 0, double a03 = 0,
        double a10 = 0, double a11 = 1, double a12 = 0, double a13 = 0,
        double a20 = 0, double a21 = 0, double a22 = 1, double a23 = 0,
        double a30 = 0, double a31 = 0, double a32 = 0, double a33 = 1
    );

    /**
     * @brief Devuelve la suma de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la suma de m1 y m2.
     */
    static Matrix4 add(const Matrix4& m1, const Matrix4& m2);

    /**
     * @brief Devuelve la matriz adjunta de la matriz actual.
     * @return Matrix4 Matriz adjunta.
     */
    Matrix4 adjoint() const;

    /**
     * @brief Devuelve una copia del objeto Matrix4.
     * @return Matrix4 Copia del objeto actual.
     */
    Matrix4 clone() const;

    /**
     * @brief Calcula el determinante de la matriz.
     * @return double Determinante de la matriz.
     */
    double determinant() const;

    /**
     * @brief Verifica si dos matrices son aproximadamente iguales.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @param epsilon Tolerancia para la comparación.
     * @return bool True si las matrices son aproximadamente iguales, false en caso contrario.
     */
    static bool equalsWithE(const Matrix4& m1, const Matrix4& m2, double epsilon);

    /**
     * @brief Multiplica la matriz por un escalar.
     * @param scalar Escalar por el cual multiplicar la matriz.
     * @return Matrix4 Resultado de la multiplicación por el escalar.
     */
    Matrix4 multiplyByScalar(double scalar) const;

    /**
     * @brief Multiplica dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la multiplicación de m1 y m2.
     */
    static Matrix4 multiply(const Matrix4& m1, const Matrix4& m2);

    /**
     * @brief Invierte la matriz actual.
     * @return Matrix4 Matriz invertida.
     * @throws std::runtime_error Si la matriz es singular (determinante cercano a cero).
     */
    Matrix4 invert() const;

    /**
     * @brief Establece la matriz como una matriz identidad.
     * @return Matrix4& Referencia a la matriz actual.
     */
    Matrix4& identity();

    /**
     * @brief Multiplica cada componente de una matriz por un escalar.
     * @param m1 Matriz a multiplicar.
     * @param c Escalar por el cual multiplicar la matriz.
     * @return Matrix4 Resultado de la multiplicación por el escalar.
     */
    static Matrix4 multiplyScalar(const Matrix4& m1, double c);

    /**
     * @brief Multiplica un vector por la matriz.
     * @param v Vector a multiplicar.
     * @return Vector4 Resultado de la multiplicación del vector por la matriz.
     */
    Vector4 multiplyVector(const Vector4& v) const;

    /**
     * @brief Establece nuevos valores para los elementos de la matriz.
     * @param a00 Valor para el elemento (0,0).
     * @param a01 Valor para el elemento (0,1).
     * @param a02 Valor para el elemento (0,2).
     * @param a03 Valor para el elemento (0,3).
     * @param a10 Valor para el elemento (1,0).
     * @param a11 Valor para el elemento (1,1).
     * @param a12 Valor para el elemento (1,2).
     * @param a13 Valor para el elemento (1,3).
     * @param a20 Valor para el elemento (2,0).
     * @param a21 Valor para el elemento (2,1).
     * @param a22 Valor para el elemento (2,2).
     * @param a23 Valor para el elemento (2,3).
     * @param a30 Valor para el elemento (3,0).
     * @param a31 Valor para el elemento (3,1).
     * @param a32 Valor para el elemento (3,2).
     * @param a33 Valor para el elemento (3,3).
     * @return Matrix4& Referencia a la matriz actual.
     */
    Matrix4& set();

    /**
     * @brief Devuelve la resta de dos matrices.
     * @param m1 Primera matriz.
     * @param m2 Segunda matriz.
     * @return Matrix4 Resultado de la resta de m1 y m2.
     */
    static Matrix4 subtract(const Matrix4& m1, const Matrix4& m2);

    /**
     * @brief Devuelve la transpuesta de la matriz actual.
     * @return Matrix4 Matriz transpuesta.
     */
    Matrix4 transpose() const;


    // Métodos estáticos de matrices de transformaciones de cámara

    /**
     * @brief Genera una matriz de proyección de perspectiva utilizando un frustum.
     * 
     * @param left Límite izquierdo del frustum.
     * @param right Límite derecho del frustum.
     * @param bottom Límite inferior del frustum.
     * @param top Límite superior del frustum.
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define el frustum.
     */
    static Matrix4 frustum(double left, double right, double bottom, double top, double near, double far) {
        return Matrix4();
    }

    /**
     * @brief Genera una matriz de vista para una cámara en una posición dada.
     * 
     * @param eye Posición de la cámara.
     * @param center Punto al que la cámara está mirando.
     * @param up Vector hacia arriba en el espacio de la cámara.
     * @return Matrix4 Matriz 4x4 que define la vista.
     */
    static Matrix4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up) {
        // TODO: Implementar la lógica del método.
        return Matrix4();
    }

    /**
     * @brief Genera una matriz de proyección ortográfica.
     * 
     * @param left Límite izquierdo de la proyección.
     * @param right Límite derecho de la proyección.
     * @param bottom Límite inferior de la proyección.
     * @param top Límite superior de la proyección.
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define la proyección ortográfica.
     */
    static Matrix4 orthographic(double left, double right, double bottom, double top, double near, double far) {
        return Matrix4();
    }

    /**
     * @brief Genera una matriz de proyección de perspectiva utilizando un campo de visión.
     * 
     * @param fovy Campo de visión en el eje vertical, en grados.
     * @param aspect Relación de aspecto (ancho/alto).
     * @param near Distancia del plano cercano.
     * @param far Distancia del plano lejano.
     * @return Matrix4 Matriz 4x4 que define la proyección de perspectiva.
     */
    static Matrix4 perspective(double fovy, double aspect, double near, double far) {

        return Matrix4();
    }

    /**
     * @brief Genera una matriz de rotación alrededor del eje X.
     * 
     * @param theta Ángulo de rotación en radianes.
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje X.
     */
    static Matrix4 rotateX(double theta) {

        return Matrix4( );
    }

    /**
     * @brief Genera una matriz de rotación alrededor del eje Y.
     * 
     * @param theta Ángulo de rotación en radianes.
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje Y.
     */
    static Matrix4 rotateY(double theta) {

        return Matrix4();
    }

        /**
     * @brief Genera una matriz de rotación alrededor del eje X.
     * 
     * @param Vector3 v
     * @return Matrix4 Matriz 4x4 que define la rotación alrededor del eje z.
     */
    static Matrix4 rotateZ(Vector3 v) {

        return Matrix4( );
    }


    /**
     * @brief Genera una matriz de escalado.
     * 
     * @param x Factor de escala en el eje X.
     * @param y Factor de escala en el eje Y.
     * @param z Factor de escala en el eje Z.
     * @return Matrix4 Matriz 4x4 que define el escalado.
     */
    static Matrix4 scale(double x, double y, double z) {
        return Matrix4();
    }

    /**
     * @brief Genera una matriz de traslación.
     * 
     * @param x Desplazamiento en el eje X.
     * @param y Desplazamiento en el eje Y.
     * @param z Desplazamiento en el eje Z.
     * @return Matrix4 Matriz 4x4 que define la traslación.
     */
    static Matrix4 translate(double x, double y, double z) {
        return Matrix4();
    }


            
};

/**
//Aqui empiezan las pruebas
int main() {
    // Pruebas para Vector3
    cout << "Pruebas para Vector3:" << endl;

    // Crear vectores
    Vector3 v1(1.0, 2.0, 3.0);
    Vector3 v2(4.0, 5.0, 6.0);

    // Producto punto
    double dotProduct = Vector3::dot(v1, v2);
    cout << "Producto punto de v1 y v2: " << dotProduct << endl;

    // Distancia entre vectores
    double dist = Vector3::distance(v1, v2);
    cout << "Distancia entre v1 y v2: " << dist << endl;

    // Distancia al cuadrado
    double squaredDist = Vector3::squaredDistance(v1, v2);
    cout << "Distancia al cuadrado entre v1 y v2: " << squaredDist << endl;


    // Comparar vectores
    bool areEqual = Vector3::equals(v1, v2);
    cout << "v1 y v2 son iguales: " << (areEqual ? "Sí" : "No") << endl;

    bool areExactEqual = Vector3::exactEquals(v1, v2);
    cout << "v1 y v2 son exactamente iguales: " << (areExactEqual ? "Sí" : "No") << endl;


    // Pruebas para Matrix3
    cout << "\nPruebas para Matrix3:" << endl;

    // Crear matrices
    Matrix3 m1;
    Matrix3 m2(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

    // Sumar matrices
    Matrix3 m3 = Matrix3::add(m1, m2);
    cout << "Suma de m1 y m2:" << endl;
    cout << m3.a00 << " " << m3.a01 << " " << m3.a02 << endl;
    cout << m3.a10 << " " << m3.a11 << " " << m3.a12 << endl;
    cout << m3.a20 << " " << m3.a21 << " " << m3.a22 << endl;

    // Restar matrices
    Matrix3 m4 = Matrix3::subtract(m2, m1);
    cout << "Resta de m2 y m1:" << endl;
    cout << m4.a00 << " " << m4.a01 << " " << m4.a02 << endl;
    cout << m4.a10 << " " << m4.a11 << " " << m4.a12 << endl;
    cout << m4.a20 << " " << m4.a21 << " " << m4.a22 << endl;

    // Multiplicación de matrices
    Matrix3 m5 = Matrix3::multiply(m1, m2);
    cout << "Multiplicación de m1 y m2:" << endl;
    cout << m5.a00 << " " << m5.a01 << " " << m5.a02 << endl;
    cout << m5.a10 << " " << m5.a11 << " " << m5.a12 << endl;
    cout << m5.a20 << " " << m5.a21 << " " << m5.a22 << endl;

    // Multiplicación por escalar
    Matrix3 m6 = Matrix3::multiplyScalar(m2, 2.0);
    cout << "Multiplicación de m2 por escalar 2.0:" << endl;
    cout << m6.a00 << " " << m6.a01 << " " << m6.a02 << endl;
    cout << m6.a10 << " " << m6.a11 << " " << m6.a12 << endl;
    cout << m6.a20 << " " << m6.a21 << " " << m6.a22 << endl;

    // Inversión de matriz
    Matrix3 m7 = m2.invert();
    cout << "Inversa de m2:" << endl;
    cout << m7.a00 << " " << m7.a01 << " " << m7.a02 << endl;
    cout << m7.a10 << " " << m7.a11 << " " << m7.a12 << endl;
    cout << m7.a20 << " " << m7.a21 << " " << m7.a22 << endl;

    // Determinante
    double det = m2.determinant();
    cout << "Determinante de m2: " << det << endl;

    // Transpuesta de matriz
    Matrix3 m8 = m2.transpose();
    cout << "Transpuesta de m2:" << endl;
    cout << m8.a00 << " " << m8.a01 << " " << m8.a02 << endl;
    cout << m8.a10 << " " << m8.a11 << " " << m8.a12 << endl;
    cout << m8.a20 << " " << m8.a21 << " " << m8.a22 << endl;

    // Identidad
    Matrix3 m9;
    m9.identity();
    cout << "Matriz identidad:" << endl;
    cout << m9.a00 << " " << m9.a01 << " " << m9.a02 << endl;
    cout << m9.a10 << " " << m9.a11 << " " << m9.a12 << endl;
    cout << m9.a20 << " " << m9.a21 << " " << m9.a22 << endl;

    // Rotación
    Matrix3 m10 = Matrix3::rotate(3.14159265358979 / 4); // 45 grados
    cout << "Rotación de 45 grados:" << endl;
    cout << m10.a00 << " " << m10.a01 << " " << m10.a02 << endl;
    cout << m10.a10 << " " << m10.a11 << " " << m10.a12 << endl;
    cout << m10.a20 << " " << m10.a21 << " " << m10.a22 << endl;

    // Escalamiento
    Matrix3 m11 = Matrix3::scale(2.0, 3.0);
    cout << "Escalamiento (2.0, 3.0):" << endl;
    cout << m11.a00 << " " << m11.a01 << " " << m11.a02 << endl;
    cout << m11.a10 << " " << m11.a11 << " " << m11.a12 << endl;
    cout << m11.a20 << " " << m11.a21 << " " << m11.a22 << endl;

    // Traslación
    Matrix3 m12 = Matrix3::translate(5.0, 10.0);
    cout << "Traslación (5.0, 10.0):" << endl;
    cout << m12.a00 << " " << m12.a01 << " " << m12.a02 << endl;
    cout << m12.a10 << " " << m12.a11 << " " << m12.a12 << endl;
    cout << m12.a20 << " " << m12.a21 << " " << m12.a22 << endl;

    //ejemplos vector4
    Vector4 vectorA(1, 2, 3, 4);
    Vector4 vectorB(5, 6, 7, 8);

    Vector4 sumVector = Vector4::add(vectorA, vectorB);
    Vector4 clonedVector = vectorA.clone();
    double distance = Vector4::distance(vectorA, vectorB);
    double dotProduct1 = Vector4::dot(vectorA, vectorB);
    bool isApproximatelyEqual = Vector4::equals(vectorA, vectorB);
    bool isExactlyEqual = Vector4::exactEquals(vectorA, vectorB);
    Vector4 normalizedVector = vectorA.normalize();
    vectorA.set(10, 20, 30, 40);
    Vector4 differenceVector = Vector4::subtract(vectorA, vectorB);
    double squaredDistance = Vector4::squaredDistance(vectorA, vectorB);
    vectorA.zero();

    // Imprimir resultados
    cout << "Suma de Vector4: (" << sumVector.x << ", " << sumVector.y << ", " << sumVector.z << ", " << sumVector.w << ")\n";
    cout << "Clon Vector4: (" << clonedVector.x << ", " << clonedVector.y << ", " << clonedVector.z << ", " << clonedVector.w << ")\n";
    cout << "Distancia Vector4: " << distance << "\n";
    cout << "Prodcuto punto Vector4: " << dotProduct << "\n";
    cout << "Approximately Equal: " << (isApproximatelyEqual ? "true" : "false") << "\n";
    cout << "Exactly Equal: " << (isExactlyEqual ? "true" : "false") << "\n";
    cout << "Normalized Vector4: (" << normalizedVector.x << ", " << normalizedVector.y << ", " << normalizedVector.z << ", " << normalizedVector.w << ")\n";
    cout << "Difference Vector4: (" << differenceVector.x << ", " << differenceVector.y << ", " << differenceVector.z << ", " << differenceVector.w << ")\n";
    cout << "Squared Distance: " << squaredDistance << "\n";
    cout << "Vector a cero: (" << vectorA.x << ", " << vectorA.y << ", " << vectorA.z << ", " << vectorA.w << ")\n";

    //pruebas Matrix4
        // Crear matrices
    Matrix4 mat1(1, 2, 3, 4,
                 5, 6, 7, 8,
                 9, 10, 11, 12,
                 13, 14, 15, 16);

    Matrix4 mat2(16, 15, 14, 13,
                 12, 11, 10, 9,
                 8, 7, 6, 5,
                 4, 3, 2, 1);

    // Probar métodos
    Matrix4 identityMat = mat1.identity();
    cout << "Identidad Matrix4:" << endl;
    cout << " " << identityMat.a00 << " " << identityMat.a01 << " " << identityMat.a02 << " " << identityMat.a03 << endl;
    cout << " " << identityMat.a10 << " " << identityMat.a11 << " " << identityMat.a12 << " " << identityMat.a13 << endl;
    cout << " " << identityMat.a20 << " " << identityMat.a21 << " " << identityMat.a22 << " " << identityMat.a23 << endl;
    cout << " " << identityMat.a30 << " " << identityMat.a31 << " " << identityMat.a32 << " " << identityMat.a33 << endl;

    Matrix4 result = mat1.multiplyScalar(mat1,2.0);
    cout << "Matrix 1 multiplicado por 2.0:" << endl;
    cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
    cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
    cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
    cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

    result = mat1.subtract(mat2, mat1);
    cout << "Matrix 1 menos Matrix 2:" << endl;
    cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
    cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
    cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
    cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;
    
    result = mat1.multiply(mat1, mat2);
    cout << "Matrix 1 multiplied by Matrix 2:" << endl;
    cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
    cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
    cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
    cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

    result = mat1.transpose();
    cout << "Transpose de Matrix 1:" << endl;
    cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
    cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
    cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
    cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

    result = mat1.invert();
    cout << "Inversa de Matrix 1:" << endl;
    cout << " " << result.a00 << " " << result.a01 << " " << result.a02 << " " << result.a03 << endl;
    cout << " " << result.a10 << " " << result.a11 << " " << result.a12 << " " << result.a13 << endl;
    cout << " " << result.a20 << " " << result.a21 << " " << result.a22 << " " << result.a23 << endl;
    cout << " " << result.a30 << " " << result.a31 << " " << result.a32 << " " << result.a33 << endl;

    return 0;
}

*/


