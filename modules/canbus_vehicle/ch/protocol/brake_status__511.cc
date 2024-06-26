/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus_vehicle/ch/protocol/brake_status__511.h"
#include "glog/logging.h"
#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ch {

using ::apollo::drivers::canbus::Byte;

Brakestatus511::Brakestatus511() {}
const int32_t Brakestatus511::ID = 0x511;

void Brakestatus511::Parse(const std::uint8_t* bytes, int32_t length,
                           Ch* chassis) const {
  chassis->mutable_brake_status__511()->set_overspd_env(
      overspd_env(bytes, length));
  chassis->mutable_brake_status__511()->set_brake_pedal_en_sts(
      brake_pedal_en_sts(bytes, length));
  chassis->mutable_brake_status__511()->set_brake_pedal_sts(
      brake_pedal_sts(bytes, length));
  chassis->mutable_brake_status__511()->set_brake_err(
      brake_err(bytes, length));
  chassis->mutable_brake_status__511()->set_emergency_btn_env(
      emergency_btn_env(bytes, length));
  chassis->mutable_brake_status__511()->set_front_bump_env(
      front_bump_env(bytes, length));
  chassis->mutable_brake_status__511()->set_back_bump_env(
      back_bump_env(bytes, length));
  chassis->mutable_brake_status__511()->set_brake_light_actual(
      brake_light_actual(bytes, length));
}

// config detail: {'bit': 48, 'enum': {0: 'OVERSPD_ENV_NOENV', 1:
// 'OVERSPD_ENV_OVERSPEED_ENV'}, 'is_signed_var': False, 'len': 8, 'name':
// 'overspd_env', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]',
// 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_status__511::Overspd_envType Brakestatus511::overspd_env(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Overspd_envType ret =
      static_cast<Brake_status__511::Overspd_envType>(x);
  return ret;
}

// config detail: {'bit': 0, 'description': 'brake pedal enable bit(Status)',
// 'enum': {0: 'BRAKE_PEDAL_EN_STS_DISABLE', 1: 'BRAKE_PEDAL_EN_STS_ENABLE', 2:
// 'BRAKE_PEDAL_EN_STS_TAKEOVER'}, 'is_signed_var': False, 'len': 8, 'name':
// 'brake_pedal_en_sts', 'offset': 0.0, 'order': 'intel', 'physical_range':
// '[0|2]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_status__511::Brake_pedal_en_stsType Brakestatus511::brake_pedal_en_sts(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Brake_pedal_en_stsType ret =
      static_cast<Brake_status__511::Brake_pedal_en_stsType>(x);
  return ret;
}

// config detail: {'bit': 8, 'description': 'Percentage of brake pedal(Status)',
// 'is_signed_var': False, 'len': 8, 'name': 'brake_pedal_sts', 'offset': 0.0,
// 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%',
// 'precision': 1.0, 'type': 'int'}
int Brakestatus511::brake_pedal_sts(const std::uint8_t* bytes,
                                    int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'BRAKE_ERR_NOERR', 1:
// 'BRAKE_ERR_BRAKE_SYSTEM_ERR'}, 'is_signed_var': False, 'len': 8, 'name':
// 'brake_err', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]',
// 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_status__511::Brake_errType Brakestatus511::brake_err(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Brake_errType ret =
      static_cast<Brake_status__511::Brake_errType>(x);
  return ret;
}

// config detail: {'bit': 24, 'enum': {0: 'EMERGENCY_BTN_ENV_NOENV', 1:
// 'EMERGENCY_BTN_ENV_EMERGENCY_BUTTON_ENV'}, 'is_signed_var': False, 'len': 8,
// 'name': 'emergency_btn_env', 'offset': 0.0, 'order': 'intel',
// 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type':
// 'enum'}
Brake_status__511::Emergency_btn_envType Brakestatus511::emergency_btn_env(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Emergency_btn_envType ret =
      static_cast<Brake_status__511::Emergency_btn_envType>(x);
  return ret;
}

// config detail: {'bit': 32, 'enum': {0: 'FRONT_BUMP_ENV_NOENV', 1:
// 'FRONT_BUMP_ENV_FRONT_BUMPER_ENV'}, 'is_signed_var': False, 'len': 8, 'name':
// 'front_bump_env', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]',
// 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_status__511::Front_bump_envType Brakestatus511::front_bump_env(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Front_bump_envType ret =
      static_cast<Brake_status__511::Front_bump_envType>(x);
  return ret;
}

// config detail: {'bit': 40, 'enum': {0: 'BACK_BUMP_ENV_NOENV', 1:
// 'BACK_BUMP_ENV_BACK_BUMPER_ENV'}, 'is_signed_var': False, 'len': 8, 'name':
// 'back_bump_env', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]',
// 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_status__511::Back_bump_envType Brakestatus511::back_bump_env(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Brake_status__511::Back_bump_envType ret =
      static_cast<Brake_status__511::Back_bump_envType>(x);
  return ret;
}

// config detail: {'bit': 56, 'enum': {0: 'BRAKE_LIGHT_ACTUAL_BRAKELIGHT_OFF',
// 1: 'BRAKE_LIGHT_ACTUAL_BRAKELIGHT_ON'}, 'is_signed_var': False, 'len': 1,
// 'name': 'brake_light_actual', 'offset': 0.0, 'order': 'intel',
// 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type':
// 'enum'}
Brake_status__511::Brake_light_actualType Brakestatus511::brake_light_actual(
    const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 1);

  Brake_status__511::Brake_light_actualType ret =
      static_cast<Brake_status__511::Brake_light_actualType>(x);
  return ret;
}
}  // namespace ch
}  // namespace canbus
}  // namespace apollo
