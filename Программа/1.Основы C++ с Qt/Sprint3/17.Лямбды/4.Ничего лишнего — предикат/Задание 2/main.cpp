#include <algorithm>
#include <iostream>
#include <cassert>

#include "train.h"


int CountCompartment(const std::vector<Compartment>& compartments,
                     Place is_empty, Gender gender) {
  auto predicate = [=](const Compartment& c) {
    bool places_match =
        (c.lower_left == is_empty && c.lower_right == is_empty &&
         c.upper_left == is_empty && c.upper_right == is_empty);

    bool gender_matches = (c.gender == gender);

    return places_match && gender_matches;
  };

  return std::count_if(compartments.begin(), compartments.end(), predicate);
} 

bool HasFreeCompartment(const std::vector<Compartment>& compartments,
                        Gender gender) {
  auto predicate = [gender](const Compartment& c) {
    bool is_fully_free =
        (c.lower_left == Place::FREE && c.lower_right == Place::FREE &&
         c.upper_left == Place::FREE && c.upper_right == Place::FREE);

    bool gender_matches =
        (gender == Gender::NOT_SPECIFIED) || (c.gender == gender);

    return is_fully_free && gender_matches;
  };

  return std::any_of(compartments.begin(), compartments.end(), predicate);
}

FreeCompartment HasFreeCompartment(
    const std::vector<Compartment>& compartments) {
  return FreeCompartment{.has_free_compartment_for_men =
                             HasFreeCompartment(compartments, Gender::MALE),
                         .has_free_compartment_for_women =
                             HasFreeCompartment(compartments, Gender::FEMALE),
                         .has_free_compartment_for_all = HasFreeCompartment(
                             compartments, Gender::NOT_SPECIFIED)};
}

CompartmentInfo GetCompartmentStat(
    const std::vector<Compartment>& compartments) {
  return CompartmentInfo{
      .empty_for_men =
          CountCompartment(compartments, Place::FREE, Gender::MALE),
      .empty_for_women =
          CountCompartment(compartments, Place::FREE, Gender::FEMALE),
      .empty_for_all =
          CountCompartment(compartments, Place::FREE, Gender::NOT_SPECIFIED),

      .full_for_men =
          CountCompartment(compartments, Place::NOT_FREE, Gender::MALE),
      .full_for_women =
          CountCompartment(compartments, Place::NOT_FREE, Gender::FEMALE),
      .full_for_all = CountCompartment(compartments, Place::NOT_FREE,
                                       Gender::NOT_SPECIFIED)};
}

int main() {
    Compartment free_men = {
          .gender = Gender::MALE, 
          .lower_left = Place::FREE, .lower_right = Place::FREE, 
          .upper_left = Place::FREE, .upper_right = Place::FREE};
    Compartment free_women = {
          .gender = Gender::FEMALE, 
          .lower_left = Place::FREE, .lower_right = Place::FREE, 
          .upper_left = Place::FREE, .upper_right = Place::FREE};
    Compartment free_not_spec = {
          .gender = Gender::NOT_SPECIFIED, 
          .lower_left = Place::FREE, .lower_right = Place::FREE, 
          .upper_left = Place::FREE, .upper_right = Place::FREE};
    Compartment full_men = {
          .gender = Gender::MALE, 
          .lower_left = Place::NOT_FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::NOT_FREE, .upper_right = Place::NOT_FREE};
    Compartment full_women = {
          .gender = Gender::FEMALE,
          .lower_left = Place::NOT_FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::NOT_FREE, .upper_right = Place::NOT_FREE};
    Compartment full_not_spec = {
          .gender = Gender::NOT_SPECIFIED, 
          .lower_left = Place::NOT_FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::NOT_FREE, .upper_right = Place::NOT_FREE};
    Compartment half_men = {
          .gender = Gender::MALE, 
          .lower_left = Place::FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::FREE, .upper_right = Place::NOT_FREE};
    Compartment half_women = {
          .gender = Gender::FEMALE,
          .lower_left = Place::FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::FREE, .upper_right = Place::NOT_FREE};
    Compartment half_not_spec = {
          .gender = Gender::NOT_SPECIFIED, 
          .lower_left = Place::FREE, .lower_right = Place::NOT_FREE,
          .upper_left = Place::FREE, .upper_right = Place::NOT_FREE};

    {
        std::vector<Compartment> compartments = {
          free_men
        };
        
        auto info = GetCompartmentStat(compartments);
        assert(info.empty_for_all == 0
               && info.empty_for_men == 1
               && info.empty_for_women == 0
               && info.full_for_all == 0
               && info.full_for_men == 0
               && info.full_for_women == 0);

    }

    {
        std::vector<Compartment> compartments = {
          free_men, free_men, free_women
        };
        auto info = GetCompartmentStat(compartments);
        assert(info.empty_for_all == 0
               && info.empty_for_men == 2
               && info.empty_for_women == 1
               && info.full_for_all == 0
               && info.full_for_men == 0
               && info.full_for_women == 0);

    }

    {
        std::vector<Compartment> compartments = {
          free_women, free_women, free_not_spec
        };
        auto info = GetCompartmentStat(compartments);
        assert(info.empty_for_all == 1
               && info.empty_for_men == 0
               && info.empty_for_women == 2
               && info.full_for_all == 0
               && info.full_for_men == 0
               && info.full_for_women == 0);

    }

    {
        std::vector<Compartment> compartments = {
          full_men, full_women, full_not_spec, half_women
        };
        auto info = GetCompartmentStat(compartments);
        assert(info.empty_for_all == 0
               && info.empty_for_men == 0
               && info.empty_for_women == 0
               && info.full_for_all == 1
               && info.full_for_men == 1
               && info.full_for_women == 1);

    }
    
    {
        // Полузаполненные купе не считаем.
        std::vector<Compartment> compartments = {
          half_men, full_women, half_not_spec
        };
        auto info = GetCompartmentStat(compartments);
        assert(info.empty_for_all == 0
               && info.empty_for_men == 0
               && info.empty_for_women == 0
               && info.full_for_all == 0
               && info.full_for_men == 0
               && info.full_for_women == 1);

    }
    std::cout << "ok" << std::endl;
}