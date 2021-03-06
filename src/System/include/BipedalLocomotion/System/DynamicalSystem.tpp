/**
 * @file DynamicalSystem.tpp
 * @authors Giulio Romualdi
 * @copyright 2020 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the GNU Lesser General Public License v2.1 or any later version.
 */

#ifndef BIPEDAL_LOCOMOTION_SYSTEM_DYNAMICAL_SYSTEM_TPP
#define BIPEDAL_LOCOMOTION_SYSTEM_DYNAMICAL_SYSTEM_TPP

#include <BipedalLocomotion/System/DynamicalSystem.h>

namespace BipedalLocomotion
{
namespace System
{

template <typename StateType, typename StateDerivativeType, typename InputType>
bool DynamicalSystem<StateType, StateDerivativeType, InputType>::setState(const StateType& state)
{
    m_state = state;
    return true;
}

template <typename StateType, typename StateDerivativeType, typename InputType>
bool DynamicalSystem<StateType, StateDerivativeType, InputType>::setControlInput(
    const InputType& controlInput)
{
    m_controlInput = controlInput;
    return true;
}

template <typename StateType, typename StateDerivativeType, typename InputType>
const StateType& DynamicalSystem<StateType, StateDerivativeType, InputType>::getState() const
{
    return m_state;
}

template <typename StateType, typename StateDerivativeType, typename InputType>
bool DynamicalSystem<StateType, StateDerivativeType, InputType>::initalize(
    std::weak_ptr<ParametersHandler::IParametersHandler> handler)
{
    return true;
}

} // namespace System
} // namespace BipedalLocomotion

#endif // BIPEDAL_LOCOMOTION_SYSTEM_DYNAMICAL_SYSTEM_TPP
