// 60081234  advertiser__60081234  size=316 bytes
// src: advertiser.cc
// --- callers ---
//   600df264 state_machine__600df264
// --- callees ---
//   60080ee8 FUN_60080ee8
//   60080fb8 FUN_60080fb8
//   600d88d6 FUN_600d88d6
//   600d890c FUN_600d890c
//   600d8920 FUN_600d8920
//   6010165c FUN_6010165c
//   60069780 adapter__60069780
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   6013cf40 thunk_EXT_FUN_00007d10
//   600810bc types__600810bc
//   6006a21c adapter__6006a21c
//   600d4550 FUN_600d4550
//   6013d3d8 thunk_EXT_FUN_0000b4c2


/* src: advertiser.cc */

uint advertiser__60081234(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *local_148;
  uint uStack_144;
  undefined1 local_140 [16];
  undefined1 auStack_130 [8];
  undefined1 local_128;
  undefined1 local_104;
  undefined1 auStack_a4 [8];
  undefined1 local_9c;
  undefined1 local_78;
  
  thunk_EXT_FUN_0000b4c2();
  iVar1 = DAT_60081370;
  if (((param_2 == *(int *)(param_1 + 0x54)) && (param_3 == *(int *)(param_1 + 0x58))) &&
     (*(byte *)(param_1 + 0x5c) == param_4)) {
    uVar4 = 0;
  }
  else {
    *(int *)(param_1 + 0x54) = param_2;
    *(int *)(param_1 + 0x58) = param_3;
    *(char *)(param_1 + 0x5c) = (char)param_4;
    if ((*(char *)(iVar1 + 0x1854) == '\x02') ||
       (uVar4 = adapter__6006a21c(DAT_60081374), (uVar4 & 0xff) == 0)) {
      if (param_2 == 0) {
        uVar4 = FUN_600d890c(DAT_60081374);
        if ((uVar4 & 0xff) != 0) goto LAB_6008125c;
        FUN_6010165c(0x14,PTR_s_advertiser_cc_6008137c,0x90,PTR_s_Device_is_not_advertising_60081378
                    );
      }
      else {
        FUN_600d8920(DAT_60081374,0x3c4);
        thunk_EXT_FUN_0000b5ba(auStack_130,0,0x8c);
        local_128 = 9;
        local_104 = 2;
        thunk_EXT_FUN_0000b5ba(auStack_a4,0,0x8c);
        local_9c = 9;
        local_78 = 2;
        uVar4 = types__600810bc(param_1,auStack_130);
        if (((uVar4 & 0xff) != 0) || (uVar4 = FUN_60080ee8(param_1,auStack_a4), (uVar4 & 0xff) != 0)
           ) goto LAB_6008125c;
        if (param_3 == 1) {
          uVar3 = 0xf4;
        }
        else {
          uVar3 = 0x20;
        }
        uVar4 = adapter__60069780(DAT_60081374,1,auStack_130,auStack_a4,uVar3,uVar3,param_3 == 1);
        if ((uVar4 & 0xff) != 0) goto LAB_6008125c;
        local_148 = local_140;
        uStack_144 = uVar4 & 0xff;
        local_140[0] = (char)uVar4;
        FUN_60080fb8(&local_148);
        FUN_6010165c(0x14,PTR_s_advertiser_cc_6008137c,0xac,
                     PTR_s_Advertising_with_setup_token_____6008138c,local_148);
        FUN_600d4550(&local_148);
      }
      uVar4 = FUN_600d88d6(DAT_60081374,*(undefined1 *)(param_1 + 0x5c));
      if ((uVar4 & 0xff) == 0) {
        puVar2 = PTR_s__6011b41a_0xc_60081384;
        if (*(char *)(param_1 + 0x5c) == '\0') {
          puVar2 = PTR_DAT_60081380;
        }
        FUN_6010165c(0x14,PTR_s_advertiser_cc_6008137c,0xb1,
                     PTR_s_Device_is__s_connectable_over_BL_60081388,puVar2);
        uVar4 = 0;
      }
    }
  }
LAB_6008125c:
  thunk_EXT_FUN_00007d10(param_1);
  return uVar4;
}


