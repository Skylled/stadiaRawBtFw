// 600d4902  flash_lut__600d4902  size=474 bytes
// src: flash_lut.cc
// --- callers ---
// --- callees ---
//   6005fa80 flash_lut__6005fa80
//   600cc984 FUN_600cc984
//   601016f0 FUN_601016f0
//   600cc8f8 FUN_600cc8f8
//   60101b76 FUN_60101b76
//   6013cf80 thunk_EXT_FUN_0000714c


/* src: flash_lut.cc */

uint flash_lut__600d4902(int *param_1,int param_2,char *param_3,int param_4)

{
  byte bVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint *puVar4;
  byte *pbVar5;
  uint *puVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined1 local_ac;
  undefined1 local_ab;
  undefined1 local_aa [146];
  
  uVar9 = flash_lut__6005fa80();
  if ((uVar9 & 0xff) == 0) {
    if ((((char)param_1[3] == '\x01') && ((char)param_1[6] == -1)) && (0x39fff < param_2 - 0x6000U))
    {
      pcVar7 = (char *)(**(code **)(*param_1 + 0x20))();
      pbVar5 = DAT_6005fcb8;
      puVar4 = DAT_6005fcb4;
      pbVar3 = DAT_6005fcb0;
      pcVar10 = pcVar7;
      do {
        if (pcVar7 + param_4 == pcVar10) {
          return 0;
        }
        if ((*param_3 != *pcVar10) && (*pcVar10 == -1)) {
          param_1[0x1f] = param_1[0x1f] + 1;
          bVar1 = *pbVar3;
          DataMemoryBarrier(0x1b);
          if (((bVar1 & 1) == 0) && (iVar8 = FUN_600cc8f8(pbVar3), iVar8 != 0)) {
            *puVar4 = bVar1 & 1;
            FUN_600cc984(pbVar3);
          }
          uVar9 = thunk_EXT_FUN_0000714c();
          uVar9 = ((uVar9 % 1000) * 1000 + 500) / 1000 + (uVar9 / 1000) * 1000;
          if (*puVar4 + 60000 <= uVar9) {
            *puVar4 = uVar9;
            puVar2 = PTR_s_flash_lut_cc_6005fca4;
            local_b8 = local_aa;
            local_b4 = 0x80;
            uStack_b0 = 0;
            local_ac = 0;
            local_ab = 0;
            local_aa[0] = 0;
            FUN_60101b76(&local_b8,PTR_s_Flash_write_failed__retrying_6005fca8);
            FUN_601016f0(0x1e,puVar2,0x1df,&local_b8);
          }
          uVar9 = flash_lut__6005fa80(param_1,pcVar10 + (param_2 - (int)pcVar7),param_3,
                                      (char)param_1[3]);
          puVar6 = DAT_6005fcbc;
          if ((uVar9 & 0xff) != 0) {
            return uVar9;
          }
          if (*pcVar10 != *param_3) {
            bVar1 = *pbVar5;
            DataMemoryBarrier(0x1b);
            if (((bVar1 & 1) == 0) && (iVar8 = FUN_600cc8f8(pbVar5), iVar8 != 0)) {
              *puVar6 = bVar1 & 1;
              FUN_600cc984(pbVar5);
            }
            uVar9 = thunk_EXT_FUN_0000714c();
            uVar9 = ((uVar9 % 1000) * 1000 + 500) / 1000 + (uVar9 / 1000) * 1000;
            if (*puVar6 + 60000 <= uVar9) {
              *puVar6 = uVar9;
              puVar2 = PTR_s_flash_lut_cc_6005fca4;
              local_b8 = local_aa;
              local_b4 = 0x80;
              uStack_b0 = 0;
              local_ac = 0;
              local_ab = 0;
              local_aa[0] = 0;
              FUN_60101b76(&local_b8,PTR_s_Flash_rewrite_failed_6005fcac);
              FUN_601016f0(0x28,puVar2,0x1e4,&local_b8);
            }
            param_1[0x20] = param_1[0x20] + 1;
          }
        }
        pcVar10 = pcVar10 + 1;
        param_3 = param_3 + 1;
      } while( true );
    }
    uVar9 = 0;
  }
  return uVar9;
}


