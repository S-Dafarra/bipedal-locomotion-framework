/**
 * @file bipedal_locomotion.cpp
 * @authors Giulio Romualdi, Diego Ferigo
 * @copyright 2020 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the GNU Lesser General Public License v2.1 or any later version.
 */

#include <pybind11/pybind11.h>

#include "BipedalLocomotion/Planners/Contact.h"
#include "bipedal_locomotion.h"

namespace BipedalLocomotion
{
// Create the Python module
PYBIND11_MODULE(bindings, m)
{
    // BaseTypes.cpp
    bindings::CreateBaseTypes(m);

    // QuinticSpline.cpp
    bindings::CreateQuinticSpline(m);

    // ParametersHandler.cpp
    bindings::CreateIParameterHandler(m);
    bindings::CreateStdParameterHandler(m);

    // Contacts.cpp
    bindings::CreateContact(m);
    bindings::CreateContactList(m);
    bindings::CreateContactPhase(m);
    bindings::CreateContactPhaseList(m);

    // SwingFootPlanner.cpp
    bindings::CreateSwingFootPlanner(m);

    // DCMPlanner.cpp
    bindings::CreateDCMPlanner(m);

    // TimeVaryingDCMPlanner.cpp
    bindings::CreateTimeVaryingDCMPlanner(m);
}

std::string bindings::ToString(const Planners::Contact& contact)
{
    std::stringstream pose;

    pose << "Contact(name=" + contact.name + ", pose=" + ToString(contact.pose)
                + ", activation_time=" + std::to_string(contact.activationTime)
                + ", deactivation_time=" + std::to_string(contact.deactivationTime)
                + ", type=" + std::to_string(static_cast<int>(contact.type)) + ")";

    return pose.str();
}

} // namespace BipedalLocomotion
