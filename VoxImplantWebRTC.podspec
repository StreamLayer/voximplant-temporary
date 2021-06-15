Pod::Spec.new do |s|
  s.name         = "VoxImplantWebRTC"
  s.version      = "89.1.0"
  s.summary      = "WebRTC SDK for iOS"
  s.description  = <<-DESC
    WebRTC is a free, open project that provides browsers and mobile
    applications with Real-Time Communications (RTC) capabilities via simple
    APIs.
                   DESC
  s.homepage     = "http://webrtc.org/"
  s.license      = { :type => "BSD", :file => "LICENSE" }
  s.author       = "Google Inc."

  s.ios.deployment_target  = '9.0'
  

  s.source       = { :http => 'https://s3.eu-central-1.amazonaws.com/voximplant-releases/ios-webrtc/78.5.3/VoxImplantWebRTC.zip', :sha256 => '381428502795e634f3fa43cdef56e5f05b95fbbdea45e25596afbf205fdc652f' }

  s.vendored_frameworks = "WebRTC.framework"
  
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
    
end
