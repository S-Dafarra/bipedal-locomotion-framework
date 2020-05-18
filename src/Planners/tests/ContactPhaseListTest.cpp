/**
 * @file ContactPhaseListTest.cpp
 * @authors Stefano Dafarra
 * @copyright 2020 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the GNU Lesser General Public License v2.1 or any later version.
 */

// Catch2
#include <catch2/catch.hpp>

#include <BipedalLocomotion/Planners/ContactPhaseList.h>

using namespace BipedalLocomotion::Planners;

TEST_CASE("ContactPhaseList")
{
    ContactPhaseList phaseList;

    SECTION("Set from map")
    {
        ContactListMap contactListMap;
        REQUIRE(contactListMap["left"].addContact(iDynTree::Transform::Identity(), 0.0, 1.0));
        REQUIRE(contactListMap["left"].addContact(iDynTree::Transform::Identity(), 2.0, 5.0));
        REQUIRE(contactListMap["left"].addContact(iDynTree::Transform::Identity(), 6.0, 7.0));

        REQUIRE(contactListMap["right"].addContact(iDynTree::Transform::Identity(), 0.0, 3.0));
        REQUIRE(contactListMap["right"].addContact(iDynTree::Transform::Identity(), 4.0, 7.0));

        phaseList.setLists(contactListMap);
    }

    ContactList contactListLeft, contactListRight;
    contactListLeft.setDefaultName("left");
    contactListRight.setDefaultName("right");

    REQUIRE(contactListLeft.addContact(iDynTree::Transform::Identity(), 0.0, 1.0));
    REQUIRE(contactListLeft.addContact(iDynTree::Transform::Identity(), 2.0, 5.0));
    REQUIRE(contactListLeft.addContact(iDynTree::Transform::Identity(), 6.0, 7.0));

    REQUIRE(contactListRight.addContact(iDynTree::Transform::Identity(), 0.0, 3.0));
    REQUIRE(contactListRight.addContact(iDynTree::Transform::Identity(), 4.0, 7.0));

    REQUIRE(phaseList.setLists({contactListLeft, contactListRight}));

    SECTION("Check phases")
    {
        REQUIRE(phaseList.size() == 7);

        const ContactListMap& contactListMap = phaseList.lists();
        ContactList::const_iterator expectedLeft = contactListMap.at("left").begin();
        ContactList::const_iterator expectedRight = contactListMap.at("right").begin();

        ContactPhaseList::const_iterator phase = phaseList.begin();
        REQUIRE(phase->beginTime == 0.0);
        REQUIRE(phase->endTime == 1.0);
        bool ok = phase->getContactGivenList("left")->contact_it == expectedLeft;
        REQUIRE(ok);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;
        expectedLeft++;

        REQUIRE(phase->beginTime == 1.0);
        REQUIRE(phase->endTime == 2.0);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;

        REQUIRE(phase->beginTime == 2.0);
        REQUIRE(phase->endTime == 3.0);
        ok = phase->getContactGivenList("left")->contact_it == expectedLeft;
        REQUIRE(ok);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;
        expectedRight++;

        REQUIRE(phase->beginTime == 3.0);
        REQUIRE(phase->endTime == 4.0);
        ok = phase->getContactGivenList("left")->contact_it == expectedLeft;
        REQUIRE(ok);

        phase++;

        REQUIRE(phase->beginTime == 4.0);
        REQUIRE(phase->endTime == 5.0);
        ok = phase->getContactGivenList("left")->contact_it == expectedLeft;
        REQUIRE(ok);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;
        expectedLeft++;

        REQUIRE(phase->beginTime == 5.0);
        REQUIRE(phase->endTime == 6.0);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;

        REQUIRE(phase->beginTime == 6.0);
        REQUIRE(phase->endTime == 7.0);
        ok = phase->getContactGivenList("left")->contact_it == expectedLeft;
        REQUIRE(ok);
        ok = phase->getContactGivenList("right")->contact_it == expectedRight;
        REQUIRE(ok);

        phase++;
        expectedLeft++;
        expectedRight++;

        ok = phase == phaseList.end();
        REQUIRE(ok);
        ok = expectedLeft == contactListMap.at("left").end();
        REQUIRE(ok);
        ok = expectedRight == contactListMap.at("right").end();
        REQUIRE(ok);
    }

}