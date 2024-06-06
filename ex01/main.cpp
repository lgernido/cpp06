/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:44:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/06 10:20:45 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Création d'une instance de Data
    Data data;
    data.integer = 42;
    data.floater = 3.14f;

    // Sérialisation de l'instance de Data
    uintptr_t serializedData = Serializer::serialize(&data);

    // Désérialisation de la donnée sérialisée
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Affichage des valeurs désérialisées
    std::cout << "Integer: " << deserializedData->integer << std::endl; // Attendu: 42
    std::cout << "Floater: " << deserializedData->floater << std::endl; // Attendu: 3.14

    return 0;
}
