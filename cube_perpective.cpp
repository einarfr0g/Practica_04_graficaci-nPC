#include <SFML/Graphics.hpp>
#include <utility>
#include <iostream>
#include "math.cpp"

int put_pixxel(int x,int y,sf::RenderWindow& window, sf::Color color = sf::Color::White){

    sf::RectangleShape rectangle(sf::Vector2f(1.f, 1.f));

    if(x<0 || y<0){
        return -1;
    }

    rectangle.move(x,y);

    rectangle.setFillColor(color);
    
    window.draw(rectangle);

    //std::cout<<"Ponemos pixxel en "<<x<<" "<<y<<"\n";

    return 0;
}



void Bresenham_horizontal(int x0,int y0,int x1,int y1,sf::RenderWindow& window , sf::Color color = sf::Color::White){

    if(x0>x1){

        int aux = x0;
        x0 = x1;
        x1 = aux;

        aux = y0;

        y0 = y1;
        y1 = aux;
        
    }

    int current_y=0;
    int y_change_param = 0;

    int change_in_x = x1-x0;
    int change_in_y = y1-y0;

    int direccion_y;

    if(change_in_y<0)
    direccion_y = -1;
    else 
    direccion_y = 1;

    change_in_y *= direccion_y;

    if(change_in_x != 0){

        current_y = y0;
        y_change_param = 2*change_in_y - change_in_x;

        for(int i = 0;i<change_in_x+1;i++){

            put_pixxel(x0 + i, current_y,window, color);

            if(y_change_param >= 0){

                current_y += direccion_y;
                y_change_param = y_change_param -2*change_in_x;

            }

            y_change_param = y_change_param + 2*change_in_y;

        }

    }



}

void Bresenham_vertical(int x0,int y0,int x1,int y1,sf::RenderWindow& window , sf::Color color = sf::Color::White){
    if(y0>y1){
        
        int aux = x0;
        x0 = x1;
        x1 = aux;

        aux = y0;

        y0 = y1;
        y1 = aux;

    }

    int current_x=0;
    int x_change_param = 0;

    int change_in_x = x1-x0;
    int change_in_y = y1-y0;

    int direccion_x;

    if(change_in_x<0)
    direccion_x = -1;
    else 
    direccion_x = 1;

    change_in_x *= direccion_x;

    if(change_in_y != 0){

        current_x = x0;
        x_change_param = 2*change_in_x - change_in_y;

        for(int i = 0;i<change_in_y+1;i++){

            put_pixxel(current_x, y0 + i,window, color);

            if(x_change_param >= 0){

                current_x += direccion_x;
                x_change_param = x_change_param -2*change_in_y;

            }

            x_change_param = x_change_param + 2*change_in_x;

        }

    }
}

void draw_line(int x0,int y0,int x1,int y1,sf::RenderWindow& window , sf::Color color = sf::Color::White){

    if(abs(x1-x0)>=abs(y1-y0))
    Bresenham_horizontal(x0,y0,x1,y1,window,color);
    else
    Bresenham_vertical(x0,y0,x1,y1,window,color);

}

std::pair<int,int> lerp(int x0,int y0,int x1,int y1, double param){

    std::pair<int,int> result;

    double new_x = (x0*((1-param))) + (param*x1);

    double new_y = (y0*(1-param)) + (param*y1);

    std::cout<<new_x<<" "<<new_y<<"\n";

    result.first = new_x;

    result.second = new_y;

    return result;
    
}

void Iterative_lerp(int x0,int y0,int x1,int y1, sf::RenderWindow& window){

    for(int i = 0; i<=1000;i++){

        std::pair<int,int> point_A = lerp(x0,y0,x1,y1,(double)(i)/(double)(1000));
        //std::cout<<"ponermos pixxel en "<<point_A.first<<" "<<point_A.second<<"\n";
        put_pixxel(point_A.first,point_A.second,window);

    }

}

void bezzier_curve(int x0,int y0,int x1,int y1,int x2,int y2,sf::RenderWindow& window , sf::Color color = sf::Color::White){
    
    for(int i = 0; i<=1000;i++){

        std::pair<int,int> point_A = lerp(x0,y0,x1,y1,(double)(i)/(double)(1000));

        std::cout<<"primer punto "<<point_A.first<< " "<<point_A.second<<"\n";

        std::pair<int,int> point_B = lerp(x1,y1,x2,y2,(double)(i)/(double)(1000));

        std::pair<int,int> point_C = lerp(point_A.first,point_A.second,point_B.first,point_B.second,(double)(i)/(double)(1000));

        //std::cout<<"iteracion "<<i<<"\n";
        
        put_pixxel(point_C.first,point_C.second,window,color);
    }

}

//******************************************************************************************************************************************************************* */
//WRAPPERS PARA GRAFICACIÓN DEL CUBO 


int main()
{   
    int height = 720;
    int weight = 720;

    sf::RenderWindow window(sf::VideoMode(height,weight),"práctica 2",sf::Style::Default);
    window.setFramerateLimit(30);
    double theta = 1; 
    bool click = false;
    Vector3 camera = Vector3(10,10,5);

    while(window.isOpen())
    { 

        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::EventType::MouseButtonPressed){
                camera = Vector3(camera.x-1,camera.y-1,camera.y-0.5);
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        std::vector <Vector4> puntos;

        puntos.push_back(Vector4(1,1,1,1));
        puntos.push_back(Vector4(1,1,-1,1));
        puntos.push_back(Vector4(1,-1,-1,1));
        puntos.push_back(Vector4(-1,-1,-1,1));
        puntos.push_back(Vector4(-1,1,1,1));
        puntos.push_back(Vector4(-1,1,-1,1));
        puntos.push_back(Vector4(-1,-1,1,1));
        puntos.push_back(Vector4(1,-1,1,1));

        Matrix4 RotationMatrix = Matrix4::rotateZ(theta);

        for(int i=0; i<8;i++){
            puntos[i] = RotationMatrix.multiplyVector(puntos[i]);
        }
        //Matrix4::orthographic(-2,2,-3,3,2,8)
        //Matrix4::Matrix4::lookAt(camera,Vector3(),Vector3(0,0,1))

        Matrix4 Matriz_perspective_look = Matrix4::multiply(Matrix4::perspective(90,1,2,25),Matrix4::lookAt(camera,Vector3(),Vector3(0,0,1)));

        Matrix4 final_tranformation = Matrix4::multiply(Matrix4::viewPort(720,720),Matriz_perspective_look);

        window.clear();

        Vector4 aux = Vector4();
        std::vector <Vector4> puntos_camara;

        for(Vector4 e : puntos){
            aux = final_tranformation.multiplyVector(e);
            puntos_camara.push_back(aux);
            //put_pixxel(aux.x,aux.y,window);
        }

        draw_line(puntos_camara[0].x/puntos_camara[0].w,puntos_camara[0].y/puntos_camara[0].w,puntos_camara[1].x/puntos_camara[1].w,puntos_camara[1].y/puntos_camara[1].w,window);
        draw_line(puntos_camara[1].x/puntos_camara[1].w,puntos_camara[1].y/puntos_camara[1].w,puntos_camara[5].x/puntos_camara[5].w,puntos_camara[5].y/puntos_camara[5].w,window);
        draw_line(puntos_camara[5].x/puntos_camara[5].w,puntos_camara[5].y/puntos_camara[5].w,puntos_camara[4].x/puntos_camara[4].w,puntos_camara[4].y/puntos_camara[4].w,window);
        draw_line(puntos_camara[4].x/puntos_camara[4].w,puntos_camara[4].y/puntos_camara[4].w,puntos_camara[0].x/puntos_camara[0].w,puntos_camara[0].y/puntos_camara[0].w,window);
        draw_line(puntos_camara[7].x/puntos_camara[7].w,puntos_camara[7].y/puntos_camara[7].w,puntos_camara[2].x/puntos_camara[2].w,puntos_camara[2].y/puntos_camara[2].w,window);
        draw_line(puntos_camara[2].x/puntos_camara[2].w,puntos_camara[2].y/puntos_camara[2].w,puntos_camara[3].x/puntos_camara[3].w,puntos_camara[3].y/puntos_camara[3].w,window);
        draw_line(puntos_camara[3].x/puntos_camara[3].w,puntos_camara[3].y/puntos_camara[3].w,puntos_camara[6].x/puntos_camara[6].w,puntos_camara[6].y/puntos_camara[6].w,window);
        draw_line(puntos_camara[6].x/puntos_camara[6].w,puntos_camara[6].y/puntos_camara[6].w,puntos_camara[7].x/puntos_camara[7].w,puntos_camara[7].y/puntos_camara[7].w,window);
        draw_line(puntos_camara[7].x/puntos_camara[7].w,puntos_camara[7].y/puntos_camara[7].w,puntos_camara[0].x/puntos_camara[0].w,puntos_camara[0].y/puntos_camara[0].w,window);
        draw_line(puntos_camara[2].x/puntos_camara[2].w,puntos_camara[2].y/puntos_camara[2].w,puntos_camara[1].x/puntos_camara[1].w,puntos_camara[1].y/puntos_camara[1].w,window);
        draw_line(puntos_camara[3].x/puntos_camara[3].w,puntos_camara[3].y/puntos_camara[3].w,puntos_camara[5].x/puntos_camara[5].w,puntos_camara[5].y/puntos_camara[5].w,window);
        draw_line(puntos_camara[6].x/puntos_camara[6].w,puntos_camara[6].y/puntos_camara[6].w,puntos_camara[4].x/puntos_camara[4].w,puntos_camara[4].y/puntos_camara[4].w,window);

        theta = theta + 0.1;

        
        window.display();
        
    }
    return 0;
}