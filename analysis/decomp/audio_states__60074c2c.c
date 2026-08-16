// 60074c2c  audio_states__60074c2c  size=124 bytes
// src: audio_states.cc
// --- callers ---
//   60075088 audio_states__60075088
// --- callees ---
//   60066370 keys__60066370
//   600d4550 FUN_600d4550
//   6010165c FUN_6010165c
//   6010244e FUN_6010244e


/* src: audio_states.cc */

undefined1 audio_states__60074c2c(void)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined1 uVar6;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 local_20 [16];
  
  local_28 = local_20;
  local_24 = 0;
  local_20[0] = 0;
  cVar2 = keys__60066370(0x13,7,&local_28);
  puVar1 = local_28;
  if (cVar2 == '\0') {
    iVar3 = FUN_6010244e(local_28,PTR_s_default_60074ca8);
    if (iVar3 == 0) goto LAB_60074c56;
    iVar3 = FUN_6010244e(puVar1,PTR_s_16000_60074cb4);
    if (iVar3 != 0) {
      iVar3 = FUN_6010244e(puVar1,PTR_s_48000_60074cbc);
      if (iVar3 == 0) {
        FUN_6010165c(0x14,PTR_s_audio_states_cc_60074cb0,0xaa,
                     PTR_s_Using_48_kHz_processing_rate_for_60074cc0);
        uVar6 = 1;
      }
      else {
        FUN_6010165c(0x14,PTR_s_audio_states_cc_60074cb0,0xb0,
                     PTR_s_Unknown_processing_rate_specifie_60074cc4);
        uVar6 = 0;
      }
      goto LAB_60074c64;
    }
    uVar4 = 0xa5;
    puVar5 = PTR_s_Using_16_kHz_processing_rate_for_60074cb8;
  }
  else {
LAB_60074c56:
    uVar4 = 0x9f;
    puVar5 = PTR_s_Using_the_default_processing_rat_60074cac;
  }
  uVar6 = 0;
  FUN_6010165c(0x14,PTR_s_audio_states_cc_60074cb0,uVar4,puVar5);
LAB_60074c64:
  FUN_600d4550(&local_28);
  return uVar6;
}


