// 6007a2c0  frames__6007a2c0  size=366 bytes
// src: frames.h
// src: usb_audio_receive.cc
// --- callers ---
// --- callees ---
//   600cc8f8 FUN_600cc8f8
//   600cc984 FUN_600cc984
//   600db896 FUN_600db896
//   600d5240 FUN_600d5240
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740
//   600db9fa FUN_600db9fa
//   600d53ae FUN_600d53ae
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   6013d290 thunk_EXT_FUN_00008ef2
//   600d5358 FUN_600d5358
//   60079f1c usb_audio_receive__60079f1c
//   600d3618 FUN_600d3618


/* src: frames.h
   src: usb_audio_receive.cc */

uint frames__6007a2c0(int param_1,undefined *param_2,int param_3)

{
  uint *puVar1;
  undefined *puVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined *local_b0;
  uint local_ac;
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a [130];
  
  thunk_EXT_FUN_0000b4c2(param_1 + 0x968);
  uVar4 = usb_audio_receive__60079f1c(param_1);
  uVar6 = param_3 << 2;
  if (uVar4 <= (uint)(param_3 << 2)) {
    uVar6 = uVar4;
  }
  if ((uVar6 & 0xffffffe0) == 0) {
    *(undefined1 *)(param_1 + 0x19d0) = 1;
    iVar5 = FUN_600d5240(param_1 + 0x70,5);
    pbVar3 = DAT_6007a44c;
    puVar1 = DAT_6007a430;
    uVar4 = 0;
    if (iVar5 == 0) {
      *(int *)(param_1 + 0x1a08) = *(int *)(param_1 + 0x1a08) + 1;
      DataMemoryBarrier(0x1b);
      if (((*pbVar3 & 1) == 0) && (iVar5 = FUN_600cc8f8(pbVar3), iVar5 != 0)) {
        *puVar1 = 0;
        FUN_600cc984(pbVar3);
      }
      uVar6 = FUN_600d3618();
      puVar2 = PTR_s_usb_audio_receive_cc_6007a434;
      if (*puVar1 + 10000 <= uVar6) {
        *puVar1 = uVar6;
        local_b0 = puVar2;
        local_ac = 0x60;
        local_a8 = local_9a;
        local_a4 = 0x80;
        uStack_a0 = 0;
        local_9c = 0;
        local_9b = 0;
        local_9a[0] = 0;
        FUN_600d37ac(&local_a8,PTR_s_USB_audio_receive_buffer_underru_6007a438);
        FUN_600db896(&local_a8,*(undefined4 *)(param_1 + 0x1a08));
        FUN_600d37ac(&local_a8,PTR_s_underruns__6007a43c);
        FUN_600d53ae(&local_b0);
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x19d0) = 0;
    uVar4 = 0;
    local_b0 = param_2;
    local_ac = uVar6 & 0xffffffe0;
    while (uVar6 = *(uint *)(param_1 + 0x9c0), uVar6 != 0) {
      uVar7 = *(int *)(param_1 + 0x9c8) - *(int *)(param_1 + 0x9bc);
      if (uVar7 <= uVar6) {
        uVar6 = uVar7;
      }
      iVar5 = FUN_600db9fa(&local_b0,*(int *)(param_1 + 0x9bc) + *(int *)(param_1 + 0x9c4),uVar6);
      if (iVar5 == 0) break;
      uVar4 = uVar4 + iVar5;
      uVar6 = *(int *)(param_1 + 0x9bc) + iVar5;
      *(uint *)(param_1 + 0x9bc) =
           uVar6 - *(uint *)(param_1 + 0x9c8) * (uVar6 / *(uint *)(param_1 + 0x9c8));
      *(int *)(param_1 + 0x9c0) = *(int *)(param_1 + 0x9c0) - iVar5;
    }
  }
  thunk_EXT_FUN_00007d10(param_1 + 0x968);
  iVar5 = FUN_600d5358(DAT_6007a440);
  if (iVar5 == 0) {
    thunk_EXT_FUN_00008ef2(param_1 + 4);
  }
  if ((uVar4 & 3) != 0) {
    local_b0 = DAT_6007a444;
    local_ac = 0x1e;
    local_a8 = local_9a;
    local_a4 = 0x80;
    uStack_a0 = 0;
    local_9c = 0;
    local_9b = 0;
    local_9a[0] = 0;
    FUN_600d37ac(&local_a8,DAT_6007a448);
    FUN_60101740(&local_b0);
  }
  return uVar4 >> 2;
}


