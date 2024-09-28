#include "math.cpp"

int main(){
    Vector4 vec1 = Vector4(500,58,-8,97);
    Vector4 vec2 = Vector4(-23,15,0.3,-66);
    Vector4 few = Vector4(0.0000001,0.0000001,0.0000001,0.0000001);
    cout<<"La coordenada en x es: "<< to_string(vec1.x)<<" La coordenada en y es: "<< to_string(vec1.y)<<" La coordenada en z es: "<< to_string(vec1.z)<<" La coordenada en z es: "<< to_string(vec1.w)<<"\n";

    Vector4 vec3 = vec1.clone();

    vec3 = vec1.normalize();

    cout<<"La coordenada en x es: "<< to_string(vec3.x)<<" La coordenada en y es: "<< to_string(vec3.y)<<" La coordenada en z es: "<< to_string(vec3.z)<<" La coordenada en z es: "<< to_string(vec3.w)<<"\n";


    //cout<<"La coordenada en x es: "<< to_string(vec3.x)<<" La coordenada en y es: "<< to_string(vec3.y)<<" La coordenada en z es: "<< to_string(vec3.z)<<" La coordenada en z es: "<< to_string(vec3.w)<<"\n";



    //cout<<"¿Los vectores son iguales: "<< to_string(Vector4::exactEquals(vec1,vec3))<<"\n";
    //cout<<"La distancia es: "<< to_string(Vector4::distance(vec1,vec2))<<"\n";
    //cout<<"La coordenada en x es: "<< to_string(cruz.x)<<" La coordenada en y es: "<< to_string(cruz.y)<<" La coordenada en z es: "<< to_string(cruz.z)<<"\n";

}