#include "math.cpp"

int main(){
    Matrix3 mat1 = Matrix3(1,2,2,-3, 4,0,3.4,0.83,-3);

    cout<<"La matriz1 entrada a00 = "<< to_string(mat1.a00) << " entrada a01 = "<< to_string(mat1.a01)<< " entrada a02 = "<< to_string(mat1.a02)<<"\n"
    << " entrada a10 = "<< to_string(mat1.a10)<< " entrada a11 = "<< to_string(mat1.a11)<< " entrada a12 = "<< to_string(mat1.a12)<<"\n"
    << " entrada a20 = "<< to_string(mat1.a20)<< " entrada a21 = "<< to_string(mat1.a21) << " entrada a22 = "<< to_string(mat1.a22)<<"\n";

    Matrix3 mat2 = Matrix3(1,2,2,-3, 4,0,3.4,0.83,-3);

    Matrix3 mat3 = Matrix3::translate(1.5,-2.8);

    cout<<"La matriz2 entrada a00 = "<< to_string(mat3.a00)<< " entrada a01 = "<< to_string(mat3.a01)<< " entrada a02 = "<< to_string(mat3.a02)<<"\n"
                 << " entrada a10 = "<< to_string(mat3.a10)<< " entrada a11 = "<< to_string(mat3.a11)<< " entrada a12 = "<< to_string(mat3.a12)<<"\n"
                 << " entrada a20 = "<< to_string(mat3.a20)<< " entrada a21 = "<< to_string(mat3.a21)<< " entrada a22 = "<< to_string(mat3.a22)<<"\n";
    //
    Matrix3 mat4 = Matrix3::subtract(mat1,mat2);
    cout<<"La matriz2 entrada a00 = "<< to_string(mat4.a00)<< " entrada a01 = "<< to_string(mat4.a01)<< " entrada a02 = "<< to_string(mat4.a02)<<"\n"
                 << " entrada a10 = "<< to_string(mat4.a10)<< " entrada a11 = "<< to_string(mat4.a11)<< " entrada a12 = "<< to_string(mat4.a12)<<"\n"
                 << " entrada a20 = "<< to_string(mat4.a20)<< " entrada a21 = "<< to_string(mat4.a21)<< " entrada a22 = "<< to_string(mat4.a22)<<"\n";
    //
    Vector3 v = Vector3(3.1416,18,1);

    cout<<"\n"<<"\n"<<"\n";

    cout<<"v.x = "<< to_string(v.x)<<" v.y = "<< to_string(v.y)<<" v.z = "<< to_string(v.z)<<"\n";

    v = mat3.multiplyVector(v);

    cout<<"v.x = "<< to_string(v.x)<<" v.y = "<< to_string(v.y)<<" v.z = "<< to_string(v.z)<<"\n";

    //cout<<"La matrices son iguales: "<< Matrix3::exactEquals(mat1,mat3) << "\n";

    //cout<<"El determinante de la matriz es: "<<to_string(mat1.determinant())<<"\n";

    //Matrix3 mat3 = mat1.adjoint(); 

    //cout<<"La matriz3 entrada a00 = "<< to_string(mat3.a00) << " entrada a01 = "<< to_string(mat3.a01)<< " entrada a02 = "<< to_string(mat3.a02)<<"\n"
    //<< " entrada a10 = "<< to_string(mat3.a10)<< " entrada a11 = "<< to_string(mat3.a11)<< " entrada a12 = "<< to_string(mat3.a12)<<"\n"
    //<< " entrada a20 = "<< to_string(mat3.a20)<< " entrada a21 = "<< to_string(mat3.a21) << " entrada a22 = "<< to_string(mat3.a22)<<"\n";

}