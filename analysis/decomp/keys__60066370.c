// 60066370  keys__60066370  size=262 bytes
// src: keys.cc
// --- callers ---
//   60074c2c audio_states__60074c2c
//   60081ab4 gatt_server__60081ab4
//   60075088 audio_states__60075088
// --- callees ---
//   600d37b8 FUN_600d37b8
//   600d6e14 FUN_600d6e14
//   600d3a38 FUN_600d3a38
//   600d37ac FUN_600d37ac
//   6013d1a0 thunk_EXT_FUN_00008c6c
//   600662e0 dynamic_buffer__600662e0
//   60065ccc FUN_60065ccc
//   6005a01c FUN_6005a01c
//   60065db0 FUN_60065db0
//   6005a9fc FUN_6005a9fc
//   60051120 FUN_60051120
//   6004cb28 FUN_6004cb28


/* src: keys.cc */

char keys__60066370(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined *local_c4 [2];
  undefined *local_bc;
  undefined *local_b8;
  undefined *local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined1 auStack_a4 [8];
  undefined *local_9c;
  undefined *local_98;
  char local_1c;
  
  puVar2 = (undefined *)FUN_60065ccc();
  if (puVar2 == PTR_DAT_60066478) {
    FUN_60051120(&local_b4,PTR_s_keys_cc_6006647c,699,3);
    puVar2 = PTR_s_Invalid_key_60066480;
  }
  else {
    uVar6 = (uint)(byte)puVar2[0xc];
    if (uVar6 == 0) {
      iVar3 = FUN_600d6e14(param_1);
      if (iVar3 == 0) {
        if (puVar2[0x18] == '\0') {
          return '\x05';
        }
        iVar7 = *(int *)(puVar2 + 0x10);
        iVar3 = 0;
        while( true ) {
          if (param_2 == iVar3) {
            return '\x0f';
          }
          if (*(char *)(iVar7 + iVar3) == '\0') break;
          iVar3 = iVar3 + 1;
        }
        uVar4 = FUN_6004cb28(iVar7);
        FUN_6005a9fc(param_3,0,*(undefined4 *)(param_3 + 4),iVar7,uVar4);
        return '\0';
      }
      uVar4 = FUN_60065db0(param_1);
      if (param_3 != 0) {
        uVar5 = *(undefined4 *)(puVar2 + 8);
        local_c4[0] = PTR_LAB_600d3a50_1_60066488;
        local_b8 = PTR_LAB_600d3a32_1_6006648c;
        local_bc = PTR_FUN_600d3a38_1_60066490;
        local_b4 = PTR_DAT_60066494;
        local_b0 = uVar6;
        local_ac = uVar6;
        local_a8 = uVar6;
        local_9c = (undefined *)uVar6;
        FUN_600d3a38(auStack_a4,local_c4,2);
        local_98 = local_b8;
        local_9c = local_bc;
        thunk_EXT_FUN_00008c6c(local_c4);
        cVar1 = dynamic_buffer__600662e0(uVar4,uVar5,param_2,&local_b4);
        if (cVar1 == '\0') {
          FUN_6005a9fc(param_3,0,*(undefined4 *)(param_3 + 4),local_b0,local_a8);
        }
        FUN_6005a01c(&local_b4);
        return cVar1;
      }
      return '\x03';
    }
    FUN_60051120(&local_b4,PTR_s_keys_cc_6006647c,700,3);
    FUN_600d37ac(&local_ac,*(undefined4 *)(puVar2 + 8));
    puVar2 = PTR_s_is_not_a_string__60066484;
  }
  FUN_600d37ac(&local_ac,puVar2);
  FUN_600d37b8(&local_b4);
  return local_1c;
}


