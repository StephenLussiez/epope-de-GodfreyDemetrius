#include <SFML/Graphics/Drawable.hpp>;
#include <SFML/Graphics/RenderTarget.hpp>;
#include <SFML/Graphics/Sprite.hpp>;
#include <SFML/Graphics/Texture.hpp>;

#include <format>;
#include <memory>;
#include <string>;

class DrawableSprite final : public sf::Drawable
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
