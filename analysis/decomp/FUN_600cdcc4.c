// 600cdcc4  FUN_600cdcc4  size=104 bytes
// --- callers ---
//   60083678 FUN_60083678
//   60065a48 FUN_60065a48
//   6006d55c FUN_6006d55c
//   60079adc FUN_60079adc
//   6005ac18 FUN_6005ac18
//   60058318 FUN_60058318
//   600cc4a8 FUN_600cc4a8
//   6005e020 power_rpcs__6005e020
//   60051890 FUN_60051890
//   60069130 FUN_60069130
//   6006de78 FUN_6006de78
//   60065c68 FUN_60065c68
//   60079bb4 FUN_60079bb4
//   60083730 FUN_60083730
//   600cc450 FUN_600cc450
//   60068e98 FUN_60068e98
//   6005a6b0 device_info__6005a6b0
//   6006dbac FUN_6006dbac
//   6005ebe0 FUN_6005ebe0
//   6007fcbc FUN_6007fcbc
//   6005a1b0 device_info__6005a1b0
//   6008067c FUN_6008067c
//   60079bd4 FUN_60079bd4
//   6007fe74 FUN_6007fe74
//   60061b78 FUN_60061b78
//   600836a0 FUN_600836a0
//   60069dd4 FUN_60069dd4
//   6006c340 remote_device_db__6006c340
// --- callees ---
//   600cddc8 FUN_600cddc8


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_600cdcc4(undefined1 *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *local_80 [2];
  int local_78;
  undefined2 local_74;
  undefined2 local_72;
  undefined1 *local_70;
  int local_6c;
  
  puVar1 = _DAT_20003d80;
  if (param_2 < 0) {
    *_DAT_20003d80 = 0x8b;
    iVar2 = -1;
  }
  else {
    local_74 = 0x208;
    if (param_2 == 0) {
      local_78 = 0;
    }
    else {
      local_78 = param_2 + -1;
    }
    local_72 = 0xffff;
    local_80[0] = param_1;
    local_70 = param_1;
    local_6c = local_78;
    iVar2 = FUN_600cddc8(_DAT_20003d80,local_80,param_3);
    if (iVar2 < -1) {
      *puVar1 = 0x8b;
    }
    if (param_2 != 0) {
      *local_80[0] = 0;
    }
  }
  return iVar2;
}


