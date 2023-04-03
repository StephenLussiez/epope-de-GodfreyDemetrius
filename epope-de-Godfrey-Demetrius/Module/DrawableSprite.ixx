export module DrawableSprite;

import <SFML/Graphics/Drawable.hpp>;
import <SFML/Graphics/RenderTarget.hpp>;
import <SFML/Graphics/Sprite.hpp>;
import <SFML/Graphics/Texture.hpp>;

import <format>;
import <memory>;
import <string>;


namespace EGD
{
    export class DrawableSprite final : public sf::Drawable
    {
    public:
        /**
         * \brief cr�e une image � partir d'un fichier
         * \param file_path correspond au chemin vers le fichier qui sera utilis�
         */
        explicit DrawableSprite(const std::string& file_path);
        DrawableSprite() = default;

        DrawableSprite(const DrawableSprite& other);
        //DrawableSprite(const DrawableSprite& _Sprite);

        /**
         * \brief cr�e un image � partir d'une texture charg� dans la m�moire
         * \param texture est un share pointer pour chaque texture utilis� 
         */
        explicit DrawableSprite(const std::shared_ptr<sf::Texture> texture);
        ~DrawableSprite() override = default;
        /**
         * \return la position de l'image depuis en haut � gauche de l'�cran 
         */
        const sf::Vector2f& position() const noexcept { return m_sprite->getPosition(); }
        /**
         * \return le facteur de taille 
         */
        const sf::Vector2f& scale() const noexcept { return m_sprite->getScale(); }
        /**
         * \return les rebords rectangulaires de l'image 
         */
        sf::FloatRect globalBounds() const noexcept { return m_sprite->getGlobalBounds(); }
        /**
         * \return la texture sous-jacente de SFML
         */
        const sf::Texture& texture() const noexcept { return *m_sprite->getTexture(); }
        /**
         * \return le sprite sous-jacent de SFML 
         */
        const sf::Sprite& sprite() const noexcept { return *m_sprite; }
        /**
         * \return L'origin de l'image
         */
        sf::Vector2f origin() const noexcept { return m_sprite->getOrigin(); }
        /**
         * \brief Bouge l'image � la position donn�e
         * \param position correspond � la nouvelle position de l'image
         */
        void setPosition(const sf::Vector2f& position) noexcept { m_sprite->setPosition(position); }
        /**
         * \brief tourne l'image dans un angle donn�
         * \param angle correspond � l'angle en degr�
         */
        void setRotation(const float& angle) noexcept { m_sprite->setRotation(angle); }
        /**
         * brief la taille de l'image par un facteur donn�
         * \param scale correspond au nouveau facteur de la taille de l'image
         */
        void setScale(const sf::Vector2f& scale) noexcept { m_sprite->setScale(scale); }
        /**
         * \brief configure l'origine de l'image
         * \param origin correspond � l'origine de l'image 
         */
        void setOrigin(const sf::Vector2f& origin) noexcept { m_sprite->setOrigin(origin); }
        /**
         * \brief Dessine l'image sur une cible
         * \param target correspond � la cible o� l'image sera dessin�
         * \param states correspond aux �tats utilis� pour le rendu de l'image
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        std::shared_ptr<sf::Texture> m_texture;
        std::unique_ptr<sf::Sprite> m_sprite;
    };
}

module: private;

namespace EGD
{
    DrawableSprite::DrawableSprite(const std::string& file_path)
    {
        m_texture = std::make_shared<sf::Texture>();
        m_texture->loadFromFile(file_path);
        m_sprite = std::make_unique<sf::Sprite>(*m_texture);
    }

    DrawableSprite::DrawableSprite(const DrawableSprite& other)
        : m_texture(other.m_texture)
    {
        m_sprite = std::make_unique<sf::Sprite>(*m_texture);
    }

    DrawableSprite::DrawableSprite(const std::shared_ptr<sf::Texture> texture)
        : m_texture(texture)
    {
        m_sprite = std::make_unique<sf::Sprite>(*m_texture);
    }

    void DrawableSprite::draw(sf::RenderTarget& target, sf::RenderStates) const
    {
        target.draw(*m_sprite);
    }
}
