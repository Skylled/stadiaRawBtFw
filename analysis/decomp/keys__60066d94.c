// 60066d94  keys__60066d94  size=172 bytes
// src: keys.cc
// --- callers ---
//   60078e00 FUN_60078e00
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d37ac FUN_600d37ac
//   60065ccc FUN_60065ccc
//   600d74b0 FUN_600d74b0
//   600661fc keys__600661fc
//   60051120 FUN_60051120


/* src: keys.cc */

uint keys__60066d94(undefined *param_1)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined1 auStack_ac [8];
  undefined1 auStack_a4 [144];
  byte local_14;
  
  iVar1 = FUN_600d74b0();
  if (iVar1 == 0x43) {
    FUN_60051120(auStack_ac,PTR_s_keys_cc_60066e40,0x4bd,3);
    FUN_600d37ac(auStack_a4,PTR_s_No_key_found_with_name_60066e44);
  }
  else {
    puVar2 = (undefined *)FUN_60065ccc();
    if (puVar2 == PTR_DAT_60066e48) {
      FUN_60051120(auStack_ac,PTR_s_keys_cc_60066e40,0x4bf,3);
      param_1 = PTR_s_Invalid_key_60066e4c;
    }
    else if (puVar2[0xe] == '\x01') {
      FUN_60051120(auStack_ac,PTR_s_keys_cc_60066e40,0x4c1,7);
      param_1 = PTR_s_Unable_to_erase_factory_properti_60066e50;
    }
    else {
      if (puVar2[0xf] != '\0') {
        uVar3 = keys__600661fc(iVar1);
        return uVar3;
      }
      FUN_60051120(auStack_ac,PTR_s_keys_cc_60066e40,0x4c3,7);
      FUN_600d37ac(auStack_a4,PTR_s_Property_60066e54);
      FUN_600d37ac(auStack_a4,*(undefined4 *)(puVar2 + 8));
      param_1 = PTR_s_cannot_be_erased_from_the_comman_60066e58;
    }
  }
  FUN_600d37ac(auStack_a4,param_1);
  FUN_600d37b8(auStack_ac);
  return (uint)local_14;
}


