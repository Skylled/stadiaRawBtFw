// 600c3c00  FUN_600c3c00  size=618 bytes
// --- callers ---
//   600c3558 FUN_600c3558
//   600c3f04 FUN_600c3f04
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600c54ec FUN_600c54ec
//   600fa27a FUN_600fa27a
//   6006ddd8 FUN_6006ddd8
//   600efcc6 FUN_600efcc6
//   601024d8 FUN_601024d8
//   6006dbac FUN_6006dbac
//   600fa298 FUN_600fa298
//   600962dc FUN_600962dc
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c3c00(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  undefined4 local_30;
  short local_2c [2];
  short local_28;
  undefined2 *local_18;
  undefined2 local_12;
  
  local_30 = *DAT_600c3e6c;
  local_12 = 1;
  thunk_EXT_FUN_0000b5ba(local_2c,0,0x14);
  do {
    if (0x1e < *(byte *)(DAT_600c3e70 + 0x134)) {
      if ((0x1e < *(byte *)(DAT_600c3e70 + 0x134)) &&
         (local_18 = (undefined2 *)FUN_6006dbac(0x140,PTR_s_bta_dm_find_services_600c3e74,0x8a9),
         local_18 != (undefined2 *)0x0)) {
        *local_18 = 0x207;
        *(undefined4 *)(local_18 + 0x84) = *(undefined4 *)(DAT_600c3e70 + 0x10);
        FUN_600efcc6(local_18 + 4,DAT_600c3e80);
        puVar3 = local_18 + 7;
        uVar2 = FUN_600c54ec();
        FUN_601024d8(puVar3,uVar2,0xf8);
        *(undefined1 *)(local_18 + 0x83) = 0;
        FUN_600962dc(local_18);
      }
      return;
    }
    if ((*(uint *)(DAT_600c3e70 + 0xc) & 1 << *(sbyte *)(DAT_600c3e70 + 0x134)) != 0) {
      uVar2 = FUN_6006dbac(0x2ee,PTR_s_bta_dm_find_services_600c3e74,0x851);
      *(undefined4 *)(DAT_600c3e70 + 0x14) = uVar2;
      if (*(int *)(DAT_600c3e70 + 0x14) != 0) {
        if (*(int *)(DAT_600c3e70 + 8) == 0x7fffffff) {
          if ((*(uint *)(DAT_600c3e70 + 0xc) & 1) == 0) {
            local_28 = 0x100;
            *(undefined4 *)(DAT_600c3e70 + 0xc) = 0;
          }
          else {
            local_28 = 0x1200;
            *(uint *)(DAT_600c3e70 + 0xc) = *(uint *)(DAT_600c3e70 + 0xc) & 0xfffffffe;
          }
        }
        else if (*(char *)(DAT_600c3e70 + 0x134) == '\x1e') {
          if ((*(char *)(DAT_600c3e70 + 0x148) == '\0') || (*(int *)(DAT_600c3e70 + 0x144) == 0)) {
            local_28 = *(short *)(PTR_DAT_600c3e78 + (uint)*(byte *)(DAT_600c3e70 + 0x134) * 2);
          }
          else {
            thunk_EXT_FUN_0000b572
                      (local_2c,*(int *)(DAT_600c3e70 + 0x144) +
                                ((uint)*(byte *)(DAT_600c3e70 + 0x142) -
                                (uint)*(byte *)(DAT_600c3e70 + 0x148)) * 0x14,0x14);
            *(char *)(DAT_600c3e70 + 0x148) = *(char *)(DAT_600c3e70 + 0x148) + -1;
          }
          if (*(char *)(DAT_600c3e70 + 0x148) == '\0') {
            *(uint *)(DAT_600c3e70 + 0xc) =
                 *(uint *)(DAT_600c3e70 + 0xc) & ~(1 << *(sbyte *)(DAT_600c3e70 + 0x134));
          }
        }
        else {
          *(uint *)(DAT_600c3e70 + 0xc) =
               *(uint *)(DAT_600c3e70 + 0xc) & ~(1 << *(sbyte *)(DAT_600c3e70 + 0x134));
          local_28 = *(short *)(PTR_DAT_600c3e78 + (uint)*(byte *)(DAT_600c3e70 + 0x134) * 2);
        }
        if (local_2c[0] == 0) {
          local_2c[0] = 2;
        }
        if (local_28 == 0x1200) {
          local_12 = 2;
        }
        FUN_600fa27a(*(undefined4 *)(DAT_600c3e70 + 0x14),0x2ee,1,local_2c,local_12,&local_30);
        iVar1 = FUN_600fa298(param_1,*(undefined4 *)(DAT_600c3e70 + 0x14),
                             PTR_LAB_600c4070_1_600c3e7c);
        if (iVar1 != 0) {
          if (((*(char *)(DAT_600c3e70 + 0x134) != '\x1e') ||
              (*(char *)(DAT_600c3e70 + 0x148) != '\0')) &&
             (*(char *)(DAT_600c3e70 + 0x134) == '\x1e')) {
            return;
          }
          *(char *)(DAT_600c3e70 + 0x134) = *(char *)(DAT_600c3e70 + 0x134) + '\x01';
          return;
        }
        FUN_6006ddd8(*(undefined4 *)(DAT_600c3e70 + 0x14),PTR_s_bta_dm_find_services_600c3e74,0x891)
        ;
        *(undefined4 *)(DAT_600c3e70 + 0x14) = 0;
        *(undefined1 *)(DAT_600c3e70 + 0x134) = 0x1f;
      }
    }
    *(char *)(DAT_600c3e70 + 0x134) = *(char *)(DAT_600c3e70 + 0x134) + '\x01';
  } while( true );
}


