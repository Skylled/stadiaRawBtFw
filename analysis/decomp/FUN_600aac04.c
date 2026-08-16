// 600aac04  FUN_600aac04  size=384 bytes
// --- callers ---
// --- callees ---
//   600f35ae FUN_600f35ae
//   600abb14 FUN_600abb14
//   600ab110 FUN_600ab110
//   600ab424 FUN_600ab424
//   600ab8d4 FUN_600ab8d4
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600aac04(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 local_38;
  undefined2 uStack_36;
  undefined2 local_34;
  undefined2 uStack_32;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_e;
  undefined2 *local_c;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_24 = 0x10;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_38 = 2;
  uStack_36 = 0;
  local_34 = 0x1800;
  uStack_32 = 0;
  local_c = DAT_600aad84;
  thunk_EXT_FUN_0000b5ba(&local_20,0x82,0x10);
  thunk_EXT_FUN_0000b5ba(DAT_600aad84,0,0x30);
  uVar1 = FUN_600ab8d4(&local_24,DAT_600aad88);
  *(undefined1 *)(DAT_600aad8c + 0x140) = uVar1;
  FUN_600abb14(*(undefined1 *)(DAT_600aad8c + 0x140));
  local_e = FUN_600ab110(*(undefined1 *)(DAT_600aad8c + 0x140),&local_38,0,9,1);
  local_38 = 2;
  local_c[1] = 0x2a00;
  local_34 = local_c[1];
  uVar2 = FUN_600f35ae(local_e,&local_38,1,2);
  *local_c = uVar2;
  local_c[7] = 0x2a01;
  local_34 = local_c[7];
  local_c = local_c + 6;
  uVar2 = FUN_600f35ae(local_e,&local_38,1,2);
  *local_c = uVar2;
  local_c[7] = 0x2a04;
  local_34 = local_c[7];
  local_c[9] = 6;
  local_c[8] = 6;
  local_c[10] = 0;
  local_c[0xb] = 2000;
  local_c = local_c + 6;
  uVar2 = FUN_600f35ae(local_e,&local_38,1,2);
  *local_c = uVar2;
  _local_38 = CONCAT22(uStack_36,2);
  local_c[7] = 0x2aa6;
  _local_34 = CONCAT22(uStack_32,local_c[7]);
  local_c = local_c + 6;
  uVar2 = FUN_600f35ae(local_e,&local_38,1,2);
  *local_c = uVar2;
  *(undefined1 *)(local_c + 2) = 0;
  local_c = local_c + 6;
  thunk_EXT_FUN_0000b5ba(&local_20,0x81,0x10);
  FUN_600ab424(*(undefined1 *)(DAT_600aad8c + 0x140),local_e,2);
  return;
}


