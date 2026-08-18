// 600c5908  FUN_600c5908  size=734 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   601024d8 FUN_601024d8
//   600c54ec FUN_600c54ec
//   600efcc6 FUN_600efcc6
//   600f1700 FUN_600f1700
//   600d9194 thunk_FUN_6006c594
//   600f0836 FUN_600f0836


undefined1 FUN_600c5908(undefined1 param_1,undefined4 param_2,char *param_3)

{
  undefined4 uVar1;
  undefined1 auStack_138 [6];
  char local_132 [2];
  undefined4 local_130;
  undefined1 local_3a;
  undefined4 local_34;
  undefined1 local_27;
  char local_26;
  undefined1 uStack_25;
  undefined1 auStack_24 [4];
  int local_20;
  undefined1 local_19;
  
  local_19 = 0;
  if (*(int *)(DAT_600c5c1c + 0xe8) == 0) {
    local_19 = 0xb;
  }
  else {
    thunk_EXT_FUN_0000b5ba(auStack_138,0,0x118);
    switch(param_1) {
    case 1:
      thunk_FUN_6006c594(param_2,param_3,param_3 + 1,param_3 + 2,param_3 + 3,param_3 + 4,param_3 + 5
                        );
      local_19 = 0;
      break;
    case 2:
      FUN_600efcc6(auStack_138,param_2);
      local_20 = FUN_600f1700(param_2);
      if (local_20 == 0) {
        local_132[0] = '\0';
      }
      else {
        FUN_601024d8(local_132,local_20,0xf8);
      }
      local_3a = 0;
      (**(code **)(DAT_600c5c1c + 0xe8))(0x10,auStack_138);
      break;
    case 3:
      FUN_600efcc6(auStack_138,param_2);
      local_20 = FUN_600f1700(param_2);
      if (local_20 == 0) {
        local_130._0_2_ = (ushort)(byte)local_130;
      }
      else {
        FUN_601024d8((int)&local_130 + 1,local_20,0xf8);
      }
      local_3a = 0;
      local_34 = *(undefined4 *)param_3;
      (**(code **)(DAT_600c5c1c + 0xe8))(0x11,auStack_138);
      break;
    case 4:
      FUN_600efcc6(auStack_138,param_2);
      (**(code **)(DAT_600c5c1c + 0xe8))(0x12,auStack_138);
      break;
    case 5:
      FUN_600efcc6(auStack_138,param_2);
      (**(code **)(DAT_600c5c1c + 0xe8))(0x13,auStack_138);
      break;
    case 6:
      FUN_600efcc6(auStack_138,param_2);
      uVar1 = FUN_600c54ec();
      FUN_601024d8((int)&local_130 + 1,uVar1,0xf8);
      local_3a = 0;
      local_34 = *(undefined4 *)param_3;
      (**(code **)(DAT_600c5c1c + 0xe8))(0x16,auStack_138);
      break;
    case 7:
      FUN_600efcc6(auStack_138,param_2);
      FUN_600f0836(param_2,auStack_24,&uStack_25);
      local_20 = FUN_600f1700(param_2);
      if (local_20 == 0) {
        local_132[0] = '\0';
      }
      else {
        FUN_601024d8(local_132,local_20,0xf8);
      }
      if (*param_3 == '\0') {
        local_27 = 1;
      }
      else {
        local_26 = *param_3 + 'M';
      }
      if (*(int *)(DAT_600c5c1c + 0xe8) != 0) {
        (**(code **)(DAT_600c5c1c + 0xe8))(3,auStack_138);
      }
      break;
    default:
      local_19 = 0xb;
      break;
    case 0xd:
      FUN_600efcc6(auStack_138,param_2);
      local_132[0] = *param_3;
      local_130 = *(undefined4 *)(param_3 + 4);
      (**(code **)(DAT_600c5c1c + 0xe8))(0xf,auStack_138);
    }
  }
  return local_19;
}


