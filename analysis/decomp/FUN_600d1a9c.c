// 600d1a9c  FUN_600d1a9c  size=260 bytes
// --- callers ---
//   60055bd8 FUN_60055bd8
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   600d19ea FUN_600d19ea


uint FUN_600d1a9c(undefined4 param_1,byte *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_30;
  byte *local_2c;
  undefined4 *puStack_28;
  
  uStack_30 = param_1;
  local_2c = param_2;
  puStack_28 = param_3;
  uVar5 = FUN_600d19ea(param_1,param_2,&local_2c,(int)&uStack_30 + 2);
  if (uVar5 == 0) {
    bVar2 = param_3 == (undefined4 *)0x0;
    bVar3 = param_4 == (undefined4 *)0x0;
    uVar6 = 0x30;
    bVar4 = param_5 == (undefined4 *)0x0;
    uVar5 = (uint)(param_6 == (undefined4 *)0x0);
    for (; 2 < uStack_30._2_2_; uStack_30._2_2_ = uStack_30._2_2_ - bVar1) {
      bVar1 = local_2c[1];
      if (bVar1 == 0x24) {
        if (local_2c[2] == 1) {
          if ((6 < uStack_30._2_2_) && (param_3 != (undefined4 *)0x0)) {
            *param_3 = local_2c;
            bVar2 = true;
          }
        }
        else if (((local_2c[2] == 2) && (10 < uStack_30._2_2_)) && (param_4 != (undefined4 *)0x0)) {
          *param_4 = local_2c;
          bVar3 = true;
        }
      }
      else if (bVar1 == 5) {
        uVar6 = (uint)local_2c[3];
        if (((int)(uVar6 << 0x1b) < 0) || (param_5 == (undefined4 *)0x0)) {
          if (((uVar6 & 0x30) == 0x10) && (param_7 != (undefined4 *)0x0)) {
            *param_7 = local_2c;
          }
        }
        else {
          *param_5 = local_2c;
          bVar4 = true;
        }
      }
      else if (bVar1 == 0x25) {
        if (((int)(uVar6 << 0x1b) < 0) || (param_6 == (undefined4 *)0x0)) {
          if (((uVar6 & 0x30) == 0x10) && (param_8 != (undefined4 *)0x0)) {
            *param_8 = local_2c;
          }
        }
        else {
          *param_6 = local_2c;
          uVar5 = 1;
        }
      }
      bVar1 = *local_2c;
      if (uStack_30._2_2_ < bVar1) break;
      local_2c = local_2c + bVar1;
    }
    if (((bVar2) && (bVar3)) && (bVar4)) {
      uVar5 = uVar5 ^ 1;
    }
    else {
      uVar5 = 1;
    }
  }
  return uVar5;
}


