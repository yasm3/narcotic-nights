#include "Projectile.h"

Projectile::Projectile(Texture& texture, int x, int y): 
                    GameObject(texture, x, y), 
                    m_dx(0), m_dy(0),
                    m_maxSpeed(200.f), 
                    m_isActive(false),
                    m_directionSet(false)
{

}

void Projectile::update(float deltaTime, Input& m_input, const GameObject* player) {

    if ( !m_directionSet) {
        m_x=player->getPosX();
        m_y=player->getPosY();

        auto mousePosition = getMousePosition();
        int mouseX = mousePosition.first;
        int mouseY = mousePosition.second;
        // Calculer la direction du projectile en fonction de la position de la souris
        int m_directionX = mouseX - getPosX();  
        int m_directionY = mouseY - getPosY();  

        // Normaliser la direction pour obtenir un vecteur de longueur 1
        float magnitude = sqrt(m_directionX * m_directionX + m_directionY * m_directionY);
        m_dx = m_directionX / magnitude;
        m_dy = m_directionY / magnitude;
        
        m_isActive = true;
        m_directionSet = true;
    }

    // Mettre à jour la position du projectile en fonction de sa vitesse et de la direction
    setPosition(getPosX() + m_dx * m_maxSpeed * deltaTime, getPosY() + m_dy * m_maxSpeed * deltaTime);

}


void Projectile::draw(Graphics& graphics)
{
    if(m_isActive)
    {
        graphics.draw(m_texture, m_x, m_y, 30, 13);
        std::cout<<"dessine bullet"<<std::endl;
    }
    

}
bool Projectile::isActive() const
{
    return m_isActive;
}

bool Projectile::collidesWith(const GameObject& other)
{
    // Coordonnées et dimensions du joueur
    int playerX1 = m_x;
    int playerY1 = m_y;
    int playerX2 = m_x + m_w;
    int playerY2 = m_y + m_h;

    // Coordonnées et dimensions de l'autre objet
    int otherX1 = other.getPosX();
    int otherY1 = other.getPosY();
    int otherX2 = other.getPosX() + other.getWidth();
    int otherY2 = other.getPosY() + other.getHeight();

    // Vérifier la collision en utilisant la formule
    bool collision = (playerX1 < otherX2) &&
                     (playerX2 > otherX1) &&
                     (playerY1 < otherY2) &&
                     (playerY2 > otherY1);

    std::cout << "Collision: " << collision << std::endl;

    return collision;
}

void Projectile::handleCollision(GameObject& other)
{

    if ((getPosX() >= 1000 || getPosX() <= 0 || getPosY() >= 800 || getPosY() <= 0) || collidesWith(other)) {
        m_isActive = false;
    } 
}


std::pair<int, int> Projectile:: getMousePosition() const {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return std::make_pair(mouseX, mouseY);
}