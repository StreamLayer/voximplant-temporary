Pod::Spec.new do |s|
  s.name         = "VoxImplantSDK"
  s.version      = "2.40.0"
  s.summary      = "VoxImplant SDK for iOS"
  s.description  =  <<-DESC
VoxImplant iOS SDK lets you embed voice communication into your native iOS applications. It is a framework
that contains the armv7, arm64, i386 and x86_64 slices.
Bitcode is __disabled__
                   DESC

  s.homepage          = "https://voximplant.com"
  s.documentation_url = "https://voximplant.com/docs/references/iossdk"
  s.license           = { :type => "Commercial", :file => "LICENSE.txt" }
  s.authors           = "Zingaya, Inc."

  s.platform     = :ios, "9.0"
  s.source       =  { :http => 'https://s3.eu-central-1.amazonaws.com/voximplant-releases/ios-sdk/2.40.0/VoxImplant.zip', :sha256 => 'f570160ac60cb47878531e0befa36380b73c858087d04b3ce784a38e9274e15b' }

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}

  s.module_map   = 'VoxImplantSDK.modulemap'
  s.default_subspec = 'Core'

  s.subspec 'Core' do |core|
    core.source_files = 'VoxImplantSDK.{h,m}'
    core.vendored_frameworks = "VoxImplant.framework"

    core.dependency "VoxImplantWebRTC", '= 89.1.0'
  end

  s.subspec 'CocoaLumberjackLogger' do |fl|
    fl.user_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'VOXIMPLANT_COCOALUMBERJACK=1'}

    fl.source_files = "CocoaLumberjackLogger/VIClient+FileLogging.*"

    fl.dependency "VoxImplantSDK/Core"
    fl.dependency "CocoaLumberjack", '~> 3.4'
  end
end
